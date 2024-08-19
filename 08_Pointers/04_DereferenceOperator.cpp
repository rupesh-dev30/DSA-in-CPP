#include <bits/stdc++.h>
using namespace std;

/*
  # Dereferencing Operator: Get the valie of the variable pointed by any pointer.

  * operator lets us directly across & modify the value of the variable.


 * -> declare a pointer
 * -> dereferencing
 * -> Multiplication
 */

int main() {
  // code here
  int a = 10;
  int *ptr = &a;

  cout << &a << endl;
  cout << *(&a) << endl;

  cout << ptr << endl;
  cout << *ptr << endl;

  return 0;
}