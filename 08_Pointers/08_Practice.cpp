#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int x =5, y = 10;
  int *ptr1 = &x;
  int *ptr2 = &y;
  
  cout << *ptr1 << endl; // prints 5
  cout << *ptr2 << endl; // prints 5

  ptr2 = ptr1;
  cout << *ptr1 << endl; // prints 5
  cout << *ptr2 << endl; // prints 5

  return 0;
}