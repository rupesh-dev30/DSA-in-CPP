#include <bits/stdc++.h>
using namespace std;

/*
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