#include <bits/stdc++.h>
using namespace std;

class Example {
public:
  int a = 1;
};

class StaticExample {
public:
  // if we define static inside class then must have const, if we have to initialise outside the class

  // static int b = 1;  must be const else initialise outside
  static int x;
  static const int b = 100; // const it cannot be changed.
};

int StaticExample::x = 10;

int main() {
  // code here
  Example ex1;
  Example ex2;
  Example ex3;

  cout << ex1.a++ << endl;
  cout << ex2.a++ << endl;
  cout << ex3.a++ << endl;


  StaticExample ex4;
  StaticExample ex5;
  StaticExample ex6;

  cout << ex4.x++ << endl;
  cout << ex5.x++ << endl;
  cout << ex6.x++ << endl;

  return 0;
}

/*
    Static Variables:
        Variables declared as static in a function are created & initialised once for the lifetime of the program.  -> in function

        Static variables in a class are created & initialised once. They are shared by all the objects of the class.  -> in class
*/