/*
                    LIBRARY MANAGEMENT SYSTEM
    ============================================================

    PROBLEM STATEMENT: WE ARE BUILDING A LIBRARY MANAGEMENT SYSTEM WHERE WE CAN MANAGE BOOKS, MEMBERS AND TRANSACTIONS

    - ADMIN SHOULD BE ABLE TO:
        1. ADD BOOKS
        2  ADD MEMBERS
        3. BORROW BOOKS
        4. RETURN BOOKS
        5. DISPLAY BOOK AND MEMBER INFORMATION

    - KEY REQUIREMENT
        1. STORE BOOK DETAILS (ID, TITLE, AUTHOR, STATUS)
        2. STORE MEMBER DETAILS (NAME, ID, BORROWED BOOKS)
        3. TRACK WHICH BOOK IS BORROWED BY WHICH MEMBER
        4. DISPLAY DATA USING POLYMORPHISM
        5. USE MEMORY EFFICIENTLY USING CONSTRUCTOR AND DESTRUCTOR


    STEP 2:

    1. ENCAPSULATION
        - HIDES BOOK AND MEMBER DATA USING PRIVATE VARIABLES
        - PROVIDES PUBLIC METHODS (GETTER AND SETTER) TO ACCESS OR MODIFY DATA
    2. ABSTRACTION
        - PROVIDES ONLY ESSENTIAL DETAILS USING CLEAN, SIMPLE INTERFACES (EG: ADDBOOK(), BORROWBOOK())
        - AVOIDS EXPOSING INTERNAL IMPLEMENTATION
    3. INHERITANCE
        - DERIVES BOOK AND MEMBER CLASSES FROM A COMMON PERSON CLASS
        - REDUCES CODE DUPLICATION
    4. POLYMORPHISM
        - ALLOWS OVERRIDING THE DISPLAY() FUNCTION TO DISPLAY BOOK AND MEMBER INFORMATION DIFFERENTLY
        - PROVIDES FLEXIBILITY AND ENHANCES MAINTAINABILITY
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ABSTRACT CLASS (ABSTRACTION)
class Item {
  virtual void display() const = 0;
};

// BOOK CLASS
class Book : public Item {
  string title;
  string author;
  int bookId;
  static int totalBooks; // STATIC DATA MEMBER

public:
  // CONSTRUCTOR
  Book(string t, string a, int id) : title(t), author(a), bookId(id) {
    totalBooks++;
  }

  ~Book() {
    totalBooks--;
  }

  string getTitle() const { return title; }
  string getAuthor() const { return author; }
  int getBookId() const { return bookId; }

  void display() const override {
    cout << "Book ID: " << bookId << ", Title: " << title << ", Author: " << author << endl;
  }

  static void showTotalBooks() {
    cout << "Total Books in Library: " << totalBooks << endl;
  }
};

int Book::totalBooks = 0; // INITIALIZE STATIC MEMBER

class Member {
  string name;
  int memberId;
  vector<int> borrowedBooks;

public:
  Member(string n, int id) : name(n), memberId(id) {}

  int getMemberId() const { return memberId; }

  friend void displayMemberDetails(const Member &);

  void borrowBook(int bookId) {
    borrowedBooks.push_back(bookId);
    cout << name << " borrowed Book ID: " << bookId << endl;
  }

  // Return Book
  void returnBook(int bookId) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {
      if (*it == bookId) {
        borrowedBooks.erase(it);
        cout << name << " returned Book ID: " << bookId << endl;

        return;
      }
    }
    cout << "Book not found in borrowed list.\n";
  }
};

// FRIEND FUNCTION (DISPLAY MEMBER DETAILS)
void displayMemberDetails(const Member &m) {
  cout << "Member Name: " << m.name << ", Member ID: " << m.memberId << endl;

  cout << "Borrowed Books: ";
  if (m.borrowedBooks.empty()) {
    cout << "No book borrowed.\n";
  } else {
    for (int id : m.borrowedBooks) {
      cout << id << " ";
    }
    cout << endl;
  }
}

// LIBRARY CLASS (MANAGEMENT SYSTEM)
class Library {
  vector<Book> books;
  vector<Member> members;

public:
  // ADD BOOK
  void addBook(const string &title, const string &author, int bookId) {
    books.emplace_back(title, author, bookId);
  }

  // ADD MEMBER
  void addMember(const string &name, int memberId) {
    members.emplace_back(name, memberId);
  }

  // DISPLAY BOOKS
  void displayBooks() const {
    cout << "\nBOOKS IN LIBRARY:\n";
    for (const auto &book : books) {
      book.display();
    }
  }

  // DISPLAY MEMBERS
  void displayMembers() const {
    cout << "\nMEMBERS OF LIBRARY\n";
    for (const auto &member : members) {
      displayMemberDetails(member);
    }
  }

  // OPERATOR OVERLOADING (SEARCH BOOK)
  Book *operator[](int bookId) {
    for (auto &book : books) {
      if (book.getBookId() == bookId) {
        return &book;
      }
    }
    return nullptr;
  }

  // SEARCH MEMBER
  Member *searchMember(int memberId) {
    for (auto &member : members) {
      if (memberId == member.getMemberId()) {
        return &member;
      }
    }
    return nullptr;
  }
};

int main() {
  Library lib;

  // ADD BOOKS AND MEMBERS
  lib.addBook("Harry Potter", "J.K. Rowling", 101);
  lib.addBook("Can't Hurt me", "David Goggins", 102);
  lib.addBook("Never Finished", "David Goggins", 103);
  lib.addBook("Atomic Habits", "James Clear", 104);

  // DISPLAY BOOKS AND MEMBERS
  lib.displayBooks();
  lib.displayMembers();

  // BORROW AND RETURN BOOKS
  Member *member = lib.searchMember(1);
  if (member) {
    member->borrowBook(101);
  }

  member = lib.searchMember(2);
  if (member) {
    member->borrowBook(102);
  }

  // RETRUN BOOK
  member = lib.searchMember(1);
  if (member) {
    member->returnBook(101);
  }

  // SHOW TOTAL BOOKS
  Book::showTotalBooks();

  return 0;
}