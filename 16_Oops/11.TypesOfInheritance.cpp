#include <bits/stdc++.h>
using namespace std;

// Single Inheritance

class Animal {
public:
  string color;

  void eat() {
    cout << "eat \n";
  }

  void breathe() {
    cout << "breathe \n";
  }
};

class Fish : public Animal {
public:
  int fins;

  void swim() {
    cout << "swim \n";
  }
};



int main() {
  // code here
  Fish f1;
  f1.swim();
  f1.eat();
  f1.breathe();

  return 0;
}