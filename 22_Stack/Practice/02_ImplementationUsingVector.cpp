#include <bits/stdc++.h>
using namespace std;

class Stack {
  vector<int> array;
  int size = 1000;

  public: 
  void push(int x) {
    if(array.size() == size) {
      cout << "OVERFLOW" << endl;
      return;
    }

    array.push_back(x);
  }

  void pop() {
    if(array.size() == 0) {
      cout << "UNDERFLOW" << endl;
      return;
    }

    array.pop_back();
  }

  void top() {
    if(array.size() == 0) {
      cout << "EMPTY STACK" << endl;
      return;
    }

    cout << array[array.size()-1] << endl;
  }

  void isEmpty() {
    if(array.size() == 0) {
      cout << "EMPTY STACK" << endl;
      return;
    }
    cout << "NOT EMPTY STACK" << endl;
  }

  void print() {
    if(array.size() == 0) {
      cout << "EMPTY STACK" << endl;
    }

    for(int num : array) {
      cout << num << " ";
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