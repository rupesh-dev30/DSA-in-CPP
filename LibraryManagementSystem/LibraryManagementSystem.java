// All import statements go at the very top of the file
import java.util.ArrayList;
import java.util.List;

// An interface to define borrowable behavior (Abstraction)
interface Borrowable {
    void borrowItem(String memberId);
    void returnItem();
}

// Base class demonstrating Encapsulation and Abstraction
abstract class Person {
    // Encapsulated fields: private with getters/setters
    private String id;
    private String name;

    public Person(String id, String name) {
        this.id = id;
        this.name = name;
    }

    // Getters to provide controlled access to private data (Encapsulation)
    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    // Abstract method to be implemented by subclasses (Abstraction)
    public abstract void displayRole();
}

// Inheritance: Member extends Person
class Member extends Person {
    // Additional property specific to a Member
    // private int maxBooksAllowed = 5;

    public Member(String id, String name) {
        super(id, name);
    }

    @Override
    public void displayRole() {
        System.out.println(getName() + " is a library member.");
    }
}

// Inheritance: Librarian extends Person
class Librarian extends Person {
    public Librarian(String id, String name) {
        super(id, name);
    }

    @Override
    public void displayRole() {
        System.out.println(getName() + " is a librarian.");
    }

    // Librarian-specific method to add a book to the library
    public void addBook(Library library, Book book) {
        library.addBook(book);
        System.out.println("Librarian " + getName() + " added a new book: " + book.getTitle());
    }
}

// Book class demonstrates Encapsulation and Composition (a Book is part of the Library)
class Book implements Borrowable {
    private String title;
    private String author;
    private String isbn;
    private boolean isBorrowed = false;
    private String borrowedBy = null;

    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }

    // Getters (Encapsulation)
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getIsbn() {
        return isbn;
    }
    
    public boolean isBorrowed() {
        return isBorrowed;
    }

    // Implementation of Borrowable interface (Polymorphism through interface implementation)
    @Override
    public void borrowItem(String memberId) {
        if (!isBorrowed) {
            isBorrowed = true;
            borrowedBy = memberId;
            System.out.println("Book \"" + title + "\" borrowed by member " + memberId);
        } else {
            System.out.println("Book \"" + title + "\" is already borrowed.");
        }
    }

    @Override
    public void returnItem() {
        if (isBorrowed) {
            System.out.println("Book \"" + title + "\" returned by member " + borrowedBy);
            isBorrowed = false;
            borrowedBy = null;
        } else {
            System.out.println("Book \"" + title + "\" was not borrowed.");
        }
    }
}

// Library class demonstrates Composition (Library has Books) and Aggregation
class Library {
    private String name;
    private List<Book> books; // Composition: Library "has-a" list of Books

    public Library(String name) {
        this.name = name;
        this.books = new ArrayList<>();
    }

    // Encapsulation: Use methods to modify the book list
    public void addBook(Book book) {
        books.add(book);
        System.out.println("Book \"" + book.getTitle() + "\" added to library " + name);
    }

    public void displayBooks() {
        System.out.println("Books available in " + name + ":");
        for (Book book : books) {
            System.out.println("- " + book.getTitle() + " by " + book.getAuthor());
        }
    }

    // Method to find a book by title
    public Book findBookByTitle(String title) {
        for (Book book : books) {
            if (book.getTitle().equalsIgnoreCase(title)) { // using equalsIgnoreCase for a simple search
                return book;
            }
        }
        System.out.println("Book \"" + title + "\" not found in the library.");
        return null;
    }
}

// Main class to run the Library Management System (Demonstrates Polymorphism)
public class LibraryManagementSystem {
    public static void main(String[] args) {
        // Create a library
        Library library = new Library("Central Library");

        // Create some books
        Book book1 = new Book("Java OOP Concepts", "Alice Smith", "ISBN001");
        Book book2 = new Book("Advanced Java", "Bob Johnson", "ISBN002");

        // Create librarian and member (Inheritance, Polymorphism)
        Librarian librarian = new Librarian("L1", "Mr. Librarian");
        Member member = new Member("M1", "John Doe");

        // Librarian adds books to the library (Using composition)
        librarian.addBook(library, book1);
        librarian.addBook(library, book2);

        // Display all books
        library.displayBooks();

        // Member borrows a book (Using interface implementation)
        Book searchBook = library.findBookByTitle("Java OOP Concepts");
        if (searchBook != null) {
            searchBook.borrowItem(member.getId());
        }

        // Trying to borrow the same book again to show behavior
        searchBook.borrowItem(member.getId());

        // Member returns the book
        searchBook.returnItem();

        // Display roles (Polymorphism: same method name, different implementations)
        librarian.displayRole();
        member.displayRole();
    }
}
