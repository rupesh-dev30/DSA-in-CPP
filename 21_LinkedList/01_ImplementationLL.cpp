#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

  ~Node() {
    if (this->next != NULL) {
      delete this->next;
      this->next = NULL;
    }
  }
};

class List {
  Node *head;
  Node *tail;

public:
  List() {
    head = NULL;
    tail = NULL;
  }

  ~List() {
    if (head != NULL) {
      delete head;
      head = NULL;
    }
  }

  void printL() {
    Node *temp = head;

    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void push_front(int data) {
    Node *newNode = new Node(data); // dynamic
    if (head == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head; // (*newNode).next
      head = newNode;
    }
  }

  void push_back(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
      head = tail = new Node(data);
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void insert(int data, int pos) {
    Node *newNode = new Node(data);

    Node *temp = head;
    for (int i = 0; i < pos - 2; i++) {
      if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
      }
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void pop_front() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }

    Node *temp = head;
    head = head->next;

    temp->next = NULL;
    delete temp;
  }

  void pop_back() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }

    Node *temp = head;
    while (temp->next != tail) { // while(temp->next->next != NULL)
      temp = temp->next;
    }

    temp->next = NULL;
    delete tail;
    tail = temp;
  }

  int search(int key) {
    Node *temp = head;
    int position = 0;
    while (temp != NULL) {
      if (temp->data == key) {
        return position;
      } else {
        temp = temp->next;
        position++;
      }
    }
    return -1;
  }

  int helper(Node *temp, int key) {
    if (temp == NULL) {
      return -1;
    }

    if (temp->data == key) {
      return 0;
    }

    int position = helper(temp->next, key);
    if (position == -1) {
      return -1;
    }

    return position + 1;
  }

  int searchRecursively(int key) {
    return helper(head, key);
  }

  void reverse() {
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
      Node *next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }

    head = prev;
  }

  int getSize() {
    int size = 0;
    Node* temp = head;

    while(temp != NULL) {
      temp = temp->next;
      size++;
    }
    return size;
  }

  void removeNth(int pos) {
    int size = getSize();
    Node *prev = head;
    for (int i = 1; i < (size - pos); i++) {
      prev = prev->next;
    }

    Node *toDel = prev->next;
    cout << "Going to delete: " << toDel->data << endl;
    prev->next = prev->next->next;
  }
};

int main() {
  // code here
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.push_back(4);
  ll.push_back(5);
  ll.push_back(6);
  ll.push_back(7);
  ll.push_back(8);

  ll.insert(20, 3);

  ll.pop_front();
  ll.pop_back();
  cout << ll.search(6) << endl;
  cout << ll.searchRecursively(6) << endl;
  ll.printL();
  ll.reverse();
  ll.printL();

  ll.removeNth(6);
  ll.printL();

  return 0;
}

/*
    Node *newNode = new Node(data);
    this is dynamically . reason to use this rather than normal Node *newNode() is, static variable value is not accessible outside. so we need to create a dynamicaaly allocated newNode



    (*ptr).p1 = ptr->p1
*/