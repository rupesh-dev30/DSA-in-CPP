#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here

  // Creating an arrays
  int a[50];

  int b[50] = {1, 2, 3};

  int c[] = {1, 2, 3};

  cout << a << endl;
  cout << b[3] << endl;
  cout << b[1] << endl;
  cout << c << endl;

  cout << sizeof(b) / sizeof(int);

  return 0;
}

// Memory is statically allocated at compile time

/*
    Arrays:
      Linear collection of same type of elements that are stored together in contigous memory spaces;
*/