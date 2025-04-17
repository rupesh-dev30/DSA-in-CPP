#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class Stack {
  Node *head;

public:
  Stack() {
    head = nullptr;
  }

  void push(int x) {
    Node *newNode = new Node(x);

    if (head == nullptr) {
      head = newNode;
    } else {
      head->next = newNode;
      head = newNode;
    }
  }

  void pop() {
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
  }

  int top() {
    return head->data;
  }

  bool isEmpty() {
    return head == nullptr;
  }
};

int
main() {
  // code here
  Stack s;
  s.push(34);
  cout << s.top() << endl;

  return 0;
}