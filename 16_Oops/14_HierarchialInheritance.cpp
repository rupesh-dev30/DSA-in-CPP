#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
  void eat() {
    cout << "Eat \n"
         << endl;
  }
};

class Mammal : public Animal {
public:
  void walk() {
    cout << "Walk \n";
  }
};

class Fish : public Animal {
public:
  void swim() {
    cout << "Swim \n";
  }
};

int main() {
  // code here
  Fish f1;
  // f1.walk();
  f1.eat();

  Mammal m1;
  m1.walk();

  return 0;
}