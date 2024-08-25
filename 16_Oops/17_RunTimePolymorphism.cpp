#include <bits/stdc++.h>
using namespace std;

/*
    Runtime Polymorphism

     - Function Overriding
          Parent & Child both contain the same function with different implementation.
          The parent class function is said to be overridden.
*/

class Parent {
public:
  void show() {
    cout << "Parent Class" << endl;
  }
};

class Child : public Parent {
public:
  void show() {
    cout << "Child Class" << endl;
  }
};

int main() {
  // code here
  Child child;
  child.show(); // during compile time, compiler wont know which show is called.

  return 0;
}

/*
    Parent => SHOW()
      |      /
      |     /    inheritance
      v    /
    Child => SHOW()
*/