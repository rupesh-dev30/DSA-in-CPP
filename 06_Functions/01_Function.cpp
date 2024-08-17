#include <bits/stdc++.h>
using namespace std;

// Example 1: Simple Function
// This function takes two integers as parameters, adds them, and returns the result.
int add(int a, int b) {
  return a + b;
}

// Example 2: Function with No Return Value (void)
// This function prints a message to the console without returning any value.
void printMessage() {
  cout << "Hello, World!" << endl;
}

// Example 3: Function with Multiple Parameters
// This function calculates the area of a rectangle by taking the length and width as parameters.
double calculateArea(double length, double width) {
  return length * width;
}

// Example 4: Function Overloading
// Overloaded function that adds two doubles
double add(double a, double b) {
  return a + b;
}

int main() {
  // Example 1
  int result = add(5, 3);
  cout << "The sum is: " << result << endl;

  // Example 2
  printMessage();

  // Example 3
  double length = 5.5, width = 3.2;
  double area = calculateArea(length, width);
  cout << "The area of the rectangle is: " << area << endl;

  // Example 4
  int intResult = add(5, 3);           // Calls the integer version of add
  double doubleResult = add(5.5, 3.2); // Calls the double version of add

  cout << "Integer sum: " << intResult << endl;
  cout << "Double sum: " << doubleResult << endl;

  return 0;
}
