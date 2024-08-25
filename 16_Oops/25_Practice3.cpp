#include <bits/stdc++.h>
using namespace std;

class Base {
  public:
  virtual void print(){
    cout << "Base class" << endl;
  }
};

class Derived : public Base {
  public:
  void print() override{
    cout << "Derived class" << endl;
  }
};

int main() {
  // code here
  Base *b = new Derived();  //Run time polymorphism
  b->print();

  delete b;

  return 0;
}