#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
  stack<int> s1;
  stack<int> s2;

public:
  void push(int data) {
    // s1 -> s2
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(data);

    // s2 -> s1
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  void pop() {
    s1.pop();
  }

  int front() {
    return s1.top();
  }

  bool empty() {
    return s1.empty();
  }
};

int main() {
  // code here
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);

  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}