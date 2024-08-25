#include <bits/stdc++.h>
using namespace std;

class Car {
public:
  string name;
  string color;
  int *mileage;

  Car(string name, string color) {
    this->name = name;
    this->color = color;
    mileage = new int; // Dynamic Allocation
    *mileage = 12;
  }

  // Car(Car &original) {
  //   cout << "copying original to new..\n";
  //   name = original.name;
  //   color = original.color;
  //   mileage = original.mileage;
  // }

  Car(Car &original) {
    cout << "copying original to new..\n";
    name = original.name;
    color = original.color;
    mileage = new int; // giving new memory location
    *mileage = *original.mileage;
  }
};

int main() {
  // code here
  Car c1("audi", "red");
  Car c2(c1);

  cout << c2.name << endl;
  cout << c2.color << endl;
  cout << *c2.mileage << endl;

  *c2.mileage = 10;
  cout << *c2.mileage << endl;
  cout << *c1.mileage << endl;

  return 0;
}

/*
    Shallow copy copies references to original array. But array remains same.

    Deep copy created a brand new copy of the array.

    Compiler generally creates a shallow copy for array.

    We need to define own copy constructor when deep copy is needed i.e. when class contains pointers to dynamically allocated memory.
*/