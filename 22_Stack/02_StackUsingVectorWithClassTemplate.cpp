#include <bits/stdc++.h>
using namespace std;

template<class T>
class Stack {
  vector<T> v;

public:
  void push(T val) {
    v.push_back(val);
  }

  void pop() {
    if(isEmpty()) {
      cout << "Underflow";
      return;
    }
    v.pop_back();
  }

  T top() {
    // if(isEmpty()) {
    //   cout << "Empty Stack";
    //   return -1;
    // }
    int lastIndex = v.size() - 1;
    return v[lastIndex];
  }

  bool isEmpty() {
    return v.size() == 0;
  }
};

int main() {
  // code here
  Stack<char> s;
  s.push('a');
  s.push('b');
  s.push('c');

  while(!s.isEmpty()) {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}