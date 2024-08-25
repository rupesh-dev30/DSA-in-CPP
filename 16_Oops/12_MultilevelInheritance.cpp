#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
  void eat() {
    cout << "Eats \n"
         << endl;
  }

  void breathe() {
    cout << "Breathes \n"
         << endl;
  }
};

class Mammal : public Animal {
public:
  string bloodType;

  Mammal() {
    bloodType = "warm";
  }

  void walk() {
    cout << "Walks \n"
         << endl;
  }
};

class Dog : public Mammal {
public:
  void tail() {
    cout << "Wags tail \n";
  }
};

int main() {
  // code here
  Dog d1;
  d1.tail();
  d1.walk();
  d1.breathe();
  d1.eat();
  cout << d1.bloodType;

  return 0;
}