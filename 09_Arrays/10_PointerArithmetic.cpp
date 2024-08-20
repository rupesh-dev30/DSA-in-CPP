#include <bits/stdc++.h>
using namespace std;

void printArr(int *ptr, int n) {
  for (int i = 0; i < n; i++) {
    cout << *ptr << endl;
    ptr = ptr + 1;
  }
}

int main() {
  // code here
  int a = 5;
  int *ptr = &a;

  cout << ptr << endl;
  cout << (ptr + 1) << endl;
  ptr = ptr + 1;
  cout << (ptr - 1) << endl;

  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);
  printArr(arr, n);

  return 0;
}

/*
    Pointer Arithmetic
    Addition and Subtraction of constants
*/