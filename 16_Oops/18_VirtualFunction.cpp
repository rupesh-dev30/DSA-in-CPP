#include <bits/stdc++.h>
using namespace std;

/*
    Virtual Functions:
        A virtual function is a member function that you expect to be redefined in derived classes.

        - Virtual functions are Dynamic in nature
        - Defined by keyword "virtual" inside a base class and are always declared with a base class and overridden in a child class
        - Virtual functions are used to achieve runtime polymorphism
        - Virtual function is called during runtime
*/

class Parent {
public:
  void show() {
    cout << "Parent class" << endl;
  }

  virtual void hello() {
    cout << "Parent hello";
  }
};

class Child : public Parent {
public:
  void show() {
    cout << "Child class" << endl;
  }

  void hello() {
    cout << "Child hello";
  }
};

int main() {
  // code here
  Child child1;
  Parent *ptr;

  ptr = &child1; // Run time Binding
  ptr->hello();  // Virtual function

  return 0;
}