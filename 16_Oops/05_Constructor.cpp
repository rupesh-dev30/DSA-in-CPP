#include <bits/stdc++.h>
using namespace std;

/*
    Constructor:
      Special method invoked automatically at time of object creation. Used for initialisation.

        - Same name as class
        - No return type not even void
        - First parameter is reference to the class type (this)
        - Only called once (automatically), at object creation
        - Memory allocation happens when constructor is called

    "this pointer" : this is a special pointer in C++ that points to the current object

    this->prop is same as *(this).prop
*/

class Car {
  string name;
  string color;

public:
  Car() { // Constructor
    cout << "Default constructor called!!" << endl;
  }

  Car(string name, string color) { // Parametrized Constructor Called
    cout << "Parameterized constructor called!!";
    // cout << this << endl;  Address of Car.  *this -> Value of Car *(this).prop
    this->name = name;
    this->color = color;
  }

  void start() {
    cout << "Car has started.. \n";
  }

  void stop() {
    cout << "Car has stopped.. \n";
  }
};

int main() {
  // code here
  Car c1;
  Car c2("audi", "red");

  // c1.start();
  // c1.stop();

  return 0;
}