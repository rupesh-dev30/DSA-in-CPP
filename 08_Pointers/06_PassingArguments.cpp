#include <bits/stdc++.h>
using namespace std;

// Change by value
void swapByValue(int a, int b) {
  int temp = a;
  a = b;
  b = temp;

  cout << "Inside the swapByValue function" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
}

void swapByReference(int &c, int &d){
  int temp = c;
  c = d;
  d = temp;

  cout << "Inside the swapByReference function" << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;
}

void swapByReferenceWithPointer(int *e, int *f){
  int temp = *e;
  *e = *f;
  *f = temp;

  cout << "Inside the swapByReferenceWithPointer function" << endl;
  cout << "e = " << *e << endl;
  cout << "f = " << *f << endl;
}

int main() {
  // code here

  cout<<"Pass by value: "<<endl;
  int a = 5;
  int b = 10;

  cout << "Before calling swapByValue function" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  swapByValue(a, b);
  cout << "After calling swapByValue function" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;


  cout<<"Pass by reference: "<<endl;
  int c = 20;
  int d = 30;


  cout << "Before calling swapByReference function" << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;

  swapByReference(c, d);
  cout << "After calling swapByReference function" << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;

  cout<<"Pass by swapByReferenceWithPointer: "<<endl;
  int e = 50;
  int f = 10;


  cout << "Before calling swapByReferenceWithPointer function" << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;

  swapByReferenceWithPointer(&e, &f);

  cout << "After calling swapByReferenceWithPointer function" << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;

  return 0;
}

/*
    Passing Arguments:

      Pass by value:
          - A copy of the actual argument is passed to the function.
          - The function receives a copy of the argument, not the original argument.
          - Changes made to the argument within the function do not affect the original argument.

        Example:
          - int x = 5; func(x); // x remains 5

        Advantages:
          - Ensures that the function does not modify the original argument.
          - Ensures that the function does not have side effects.


      Pass by reference:
          - A reference to the actual argument is passed to the function.
          - The function receives a reference to the argument, not a copy of the argument.
          - Changes made to the argument within the function affect the original argument.

        Example:
          - int x = 5; func(&x); // x becomes 10

        Advantages:
          - Reduces the overhead of passing large objects.
          - Allows the function to modify the original argument.

*/