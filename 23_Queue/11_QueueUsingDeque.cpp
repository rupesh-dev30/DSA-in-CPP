#include <bits/stdc++.h>
using namespace std;

class Queue {
  deque<int> d;

public:
  void push(int x) {
    d.push_back(x);
  }

  void pop() {
    if (d.empty())
      return;
    d.pop_front();
  }

  int front() {
    if (d.empty())
      return -1;
    return d.front();
  }

  bool empty() {
    return d.empty();
  }
};

int main() {
  // code here
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout << q.front() << endl; // prints 1
  q.pop();
  cout << q.front() << endl; // prints 2

  return 0;
}