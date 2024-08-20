#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int a = 5;
  int *ptr = &a;

  cout << ptr << endl;
  cout << (ptr + 1) << endl;
  ptr = ptr+1;

  cout << (ptr - 1) << endl;

  return 0;
}

/*
    Pointer Arithmetic
    Addition and Subtraction of constants
*/