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

class Queue {
private:
  Node *head;
  Node *tail;

public:
  Queue() {
    head = tail = nullptr;
  }

  void push(int data) {
    Node *newNode = new Node(data);

    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void pop() {
    // if (head == nullptr) {
    //   cout << "Underflow" << endl;
    //   return;
    // }

    if(empty()) {
      cout << "Underflow" << endl;
      return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
  }

  int front() {
    // if(head == nullptr){
    //   cout << "Empty Queue" << endl;
    //   return -1;
    // }

    if(empty()) {
      cout << "Empty Queue" << endl;
      return -1;
    }

    return head->data;
  }

  bool empty() {
    return head == nullptr;
  }
};

int main() {
  // code here
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  while(!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}