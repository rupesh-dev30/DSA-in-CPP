#include <bits/stdc++.h>
using namespace std;

class A {
public:
  A() {
    cout << "Constructor A" << endl;
  }

  ~A() {
    cout << "Destructor A" << endl;
  }
};

class B : public A {
public:
  B() {
    cout << "Constructor B" << endl;
  }
  ~B() {
    cout << "Destructor B" << endl;
  }
};

int main() {
  // code here
  B obj; 

  return 0;
}


/*
    When we create a object, 
      1. Parent class constructor is called.
      2. Child class constructor is called.
      3. Child class destructor is called.
      4. Parent class destructor is called.

*/