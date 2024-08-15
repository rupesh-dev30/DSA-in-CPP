#include <bits/stdc++.h>
using namespace std;

int main(){
  // code here
  int a = 10;
  int b = 20;
  int sum, difference, product, quotient, remainder;

  // Addition
  sum = a + b;
  cout << "Addition: " << a << " + " << b << " = " << sum << endl;

  // Subtraction
  difference = a - b;
  cout << "Subtraction: " << a << " - " << b << " = " << difference << endl;

  // Multiplication
  product = a * b;
  cout << "Multiplication: " << a << " * " << b << " = " << product << endl;

  // Division
  quotient = a / b;
  cout << "Division: " << a << " / " << b << " = " << quotient << endl;

  // Modulus
  remainder = a % b;
  cout << "Modulus: " << a << " % " << b << " = " << remainder << endl;

  // Compound Assignment Operators
  int x = 15;
  x += 10; // Equivalent to x = x + 10
  cout << "Addition Assignment: x += 10; x = " << x << endl;

  int y = 20;
  y -= 5; // Equivalent to y = y - 5
  cout << "Subtraction Assignment: y -= 5; y = " << y << endl;

  int z = 4;
  z *= 5; // Equivalent to z = z * 5
  cout << "Multiplication Assignment: z *= 5; z = " << z << endl;

  int w = 50;
  w /= 10; // Equivalent to w = w / 10
  cout << "Division Assignment: w /= 10; w = " << w << endl;

  int m = 23;
  m %= 5; // Equivalent to m = m % 5
  cout << "Modulus Assignment: m %= 5; m = " << m << endl;

  // Unary Operators
  int p = 5;

  // Unary plus
  cout << "Unary Plus: +p = " << +p << endl; // No change

  // Unary minus
  cout << "Unary Minus: -p = " << -p << endl; // Negates value

  // Increment
  cout << "Increment: p = " << p << "; ++p = " << ++p << endl; // Pre-increment

  // Decrement
  cout << "Decrement: p = " << p << "; --p = " << --p << endl; // Pre-decrement

  // Post-increment and Post-decrement
  p = 10;
  cout << "Post-Increment: p = " << p << "; p++ = " << p++ << "; After increment, p = " << p << endl;
  cout << "Post-Decrement: p = " << p << "; p-- = " << p-- << "; After decrement, p = " << p << endl;

  // Relational Operators
  cout << "Relational Operators:" << endl;

  cout << a << " == " << b << " : " << (a == b ? "true" : "false") << endl; // Equal to
  cout << a << " != " << b << " : " << (a != b ? "true" : "false") << endl; // Not equal to
  cout << a << " > " << b << " : " << (a > b ? "true" : "false") << endl;   // Greater than
  cout << a << " < " << b << " : " << (a < b ? "true" : "false") << endl;   // Less than
  cout << a << " >= " << b << " : " << (a >= b ? "true" : "false") << endl; // Greater than or equal to
  cout << a << " <= " << b << " : " << (a <= b ? "true" : "false") << endl; // Less than or equal to

  // Logical Operators
  bool condition1 = (a < b);  // true
  bool condition2 = (a == b); // false

  cout << "Logical Operators:" << endl;

  // Logical AND (&&)
  cout << "Logical AND: (" << condition1 << " && " << condition2 << ") = " << (condition1 && condition2 ? "true" : "false") << endl;

  // Logical OR (||)
  cout << "Logical OR: (" << condition1 << " || " << condition2 << ") = " << (condition1 || condition2 ? "true" : "false") << endl;

  // Logical NOT (!)
  cout << "Logical NOT: !(" << condition1 << ") = " << (!condition1 ? "true" : "false") << endl;
  cout << "Logical NOT: !(" << condition2 << ") = " << (!condition2 ? "true" : "false") << endl;

  return 0;
}

/*
    Symbols that tell compiler to perform some operation

    a + b :
      a and b are operands
      + is operator

    # Types of operators

      1) Arithmetic Operator
          -> Binary Operator
              Addition (+)
              Subtraction (-)
              Multiplication (*)
              Division (/)
              Modulus (%)
              Exponentiation (^)


          -> Unary Operator
              Increment (++)
              Decrement (--)


      2) Assignment Operator
      3) Relational Operator
      4) Logical Operator
      5) Bitwise Operator
      6) Special Operator

*/