#include <bits/stdc++.h>
using namespace std;

/*
    Abstraction:
      Hiding all unnecessary details & showing only the important parts.
*/

// Abstract Class
class Shape {
public:
  virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
  void draw() {
    cout << "Drawing Circle" << endl;
  }
};

class Square : public Shape {
public:
  void draw() {
    cout << "Drawing Square" << endl;
  }
};

int main() {
  // code here
  Circle circle1;
  circle1.draw();
  Square square1;
  square1.draw();

  // Shape s1;
  // s1.draw();  Error

  return 0;
}

/*
      Encapsulation is the bundling of data and methods that operate on that data within a single unit (class), restricting access to certain components.

      Abstraction, on the other hand, is the process of hiding complex implementation details and showing only the essential features to the user.


      * Abstract classes & Pure virtual function are used to implement Abstraction

      # Abstract class: An abstract class in C++ is a class that cannot be instantiated on its own and is used to define a common interface for derived classes. It contains at least one pure virtual function, which is declared by assigning 0 to the function declaration.

      # Pure virtual function: A pure virtual function in C++ is a virtual function that has no implementation in the base class and is meant to be overridden by derived classes. It is declared by assigning 0 to the function declaration in the base class. This makes the class abstract, meaning it cannot be instantiated directly.
*/