#include <bits/stdc++.h>
using namespace std;

/*
    Special Constructor (default) used to copy properties of one object into another.
*/

class Car {
public:
  string name;
  string color;

  Car(string name, string color) {
    this->name = name;
    this->color = color;
  }

  //Custom copy constructor
  Car(Car &original) {
    cout << "Copying original to new ... \n";
    name = original.name;
    color = original.color;
  }
};

int main() {
  // code here
  Car c1("audi", "red");

  Car c2(c1); // default when Custom not created
  cout << c2.name << endl;
  cout << c2.color << endl;

  return 0;
}