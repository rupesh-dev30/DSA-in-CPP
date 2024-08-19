#include <bits/stdc++.h>
using namespace std;

/*
   NULL Pointer :
      We assign NULL value to a pointer to show that it doesn't point to any location

      int *ptr = NULL;

      Dereferencing null ptr is not possible as it'll result in error.
*/

int main() {
  // code here
  int *ptr;
  cout << ptr << endl;
  cout << *ptr << endl;

  int *ptr1 = NULL;     // it store the 0 address.
  cout << ptr1 << endl; // this is not possible, as it give error but in my case it run with no output (expected error: segmenetation fault)
  cout << *ptr1 << endl;

  return 0;
}