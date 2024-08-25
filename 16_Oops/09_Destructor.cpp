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

  ~Car(){
    cout<<"Destuctor Called!"<<endl;

    if(mileage != NULL) {
      delete mileage;
      mileage = NULL;  // Optional, this is because when we delete mileage, it storage garbage value so we initialise with NULL
    }
  }
};

int main() {
  // code here
  Car c1("audi", "red");
  cout << c1.name << endl;
  cout << c1.color << endl;
  cout << *c1.mileage << endl;

  return 0;
}