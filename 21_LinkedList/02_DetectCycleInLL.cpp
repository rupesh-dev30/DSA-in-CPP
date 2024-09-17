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
public:
  Node *head;
  Node *tail;

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

  void push_front(int data) {
    Node *newNode = new Node(data); // dynamic
    if (head == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head; // (*newNode).next
      head = newNode;
    }
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
};

void printL(Node *head) {
  Node *temp = head;

  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

bool isCycle(Node *head) {
  if (head == NULL)
    return false;

  Node *fast = head;
  Node *slow = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }
  return false;
}

int main() {
  // code here
  List ll;
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);

  ll.tail->next = ll.head;

  if (isCycle(ll.head)) {
    cout << "Cycle detected" << endl;
  } else {
    cout << "No cycle detected" << endl;
  }

  return 0;
}