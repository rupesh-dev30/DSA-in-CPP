#include <bits/stdc++.h>
using namespace std;

// Circular Queue implementation using array

class Queue {
private:
  int *arr;
  int capacity;
  int currSize;
  int r;
  int f;

public:
  Queue(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    currSize = 0;

    f = 0, r = -1;
  }

  void push(int data) {
    if (currSize == capacity) {
      cout << "Queue is Full" << endl;
      return;
    }
    r = (r + 1) % capacity;
    arr[r] = data;
    currSize++;
  }

  void pop() {
    // if (currSize == 0) {
    //   cout << "Queue is Empty" << endl;
    //   return;
    // }

    if (empty()) {
      cout << "Queue is Empty" << endl;
      return;
    }

    f = (f + 1) % capacity;
    currSize--;
  }

  int front() {
    if (empty()) {
      cout << "Queue is Empty" << endl;
      return -1;
    }

    return arr[f];
  }

  bool empty() {
    return currSize == 0;
  }
};

int main() {
  // code here
  Queue q(4);

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}