#include <bits/stdc++.h>
using namespace std;

// create stack using vector
class Stack {
  vector<int> v;

public:
  void push(int val) {
    v.push_back(val);
  }

  void pop() {
    if(isEmpty()) {
      cout << "Underflow";
      return;
    }
    v.pop_back();
  }

  int top() {
    if(isEmpty()) {
      cout << "Empty Stack";
      return -1;
    }
    int lastIndex = v.size() - 1;
    return v[lastIndex];
  }

  bool isEmpty() {
    return v.size() == 0;
  }
};

int main() {
  // code here
  Stack s;
  s.push(2);
  s.push(3);
  s.push(4);

  while(!s.isEmpty()) {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}

/*
    Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end (top) and an element is removed from that end only.

    Stack uses an encapsulated object of either vector or deque (by default) or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.
*/