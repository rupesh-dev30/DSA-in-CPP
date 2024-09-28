#include <bits/stdc++.h>
using namespace std;

class Stack {
  deque<int> d;

public:
  void push(int x) {
    d.push_front(x);
  }

  void pop() {
    if (d.empty())
      return;
    d.pop_front();
  }

  int top() {
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
  Stack s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}