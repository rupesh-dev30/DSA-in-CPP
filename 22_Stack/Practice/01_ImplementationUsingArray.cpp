#include <bits/stdc++.h>
using namespace std;

class Stack {
  static const int MAX = 1000; // MAX SIZE OF STACK
  int arr[MAX];
  int topIndex;

  public:
  Stack() {
    topIndex = -1;
  }

  void push(int x) {
    if(topIndex >= MAX-1) {
      cout << "Overflow" << endl;
      return;
    }

    arr[++topIndex] = x;
  }

  void pop() {
    if(topIndex == -1) {
      cout << "Underflow" << endl;
      return;
    }
    topIndex--;
  }
  
  void top() {
    if(topIndex == -1) {
      cout << "Empty Stack" << endl;
      return;
    }

    cout << arr[topIndex] << endl;
  }

  void isEmpty() {
     if(topIndex == -1) {
      cout << "EMPTY STACK" << endl;
      return;
     }
     cout << "NOT EMPTY" << endl;
  }

  void print() {
    if(topIndex == -1) {
      cout << "Empty Stack" << endl;
      return;
    }

    for(int i=0; i<topIndex+1; i++) {
      cout << arr[i] << " ";
    }

    cout << endl;
  }
};

int main() {
  // code here
  Stack s;
  s.isEmpty();
  s.push(45);
  s.push(20);
  s.push(30);
  s.push(14);

  s.print();

  s.pop();
  s.print();
  s.push(100);
  s.print();
  s.top();
  s.isEmpty();

  return 0;
}