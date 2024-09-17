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

  void push_back(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
      head = tail = new Node(data);
    } else {
      tail->next = newNode;
      tail = newNode;
    }
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

Node *splitAtMid(Node *head) {
  Node *slow = head;
  Node *fast = head;
  Node *prev = NULL;

  while (fast != NULL && fast->next != NULL) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  if (prev != NULL) {
    prev->next = NULL; // split at middle
  }
  return slow;
}

Node *merge(Node *left, Node *right) {
  if (!left)
    return right;
  if (!right)
    return left;

  Node *result = NULL;

  if (left->data <= right->data) {
    result = left;
    result->next = merge(left->next, right);
  } else {
    result = right;
    result->next = merge(left, right->next);
  }

  return result;
}

Node *mergeSort(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *rightHead = splitAtMid(head);
  Node *left = mergeSort(head);
  Node *right = mergeSort(rightHead);

  return merge(left, right);
}

Node *reverse(Node *head) {
  Node *prev = NULL;
  Node *curr = head;

  while (curr != NULL) {
    Node *next = curr->next;

    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev; // prev is head
}

Node *zigZag(Node *head) {
  Node *rightHead = splitAtMid(head);
  Node *rightHeadReverse = reverse(rightHead);

  // alternate merging
  Node *left = head;
  Node *right = rightHeadReverse;
  Node *nextLeft = NULL;
  Node *nextRight = NULL;
  Node *tail = head;

  while (left != NULL && right != NULL) {
    nextLeft = left->next;
    left->next = right;

    nextRight = right->next;
    right->next = nextLeft;

    tail = right;
    left = nextLeft;
    right = nextRight;
  }

  if (right != NULL) {
    tail->next = right;
  }
  return head;
}

int main() {
  // code here
  List ll;
  ll.push_back(4);
  ll.push_back(3);
  ll.push_back(2);
  ll.push_back(1);
  ll.push_back(5);
  ll.push_back(7);
  ll.push_back(9);
  ll.push_back(11);

  printL(ll.head);

  ll.head = zigZag(ll.head);

  printL(ll.head);

  return 0;
}