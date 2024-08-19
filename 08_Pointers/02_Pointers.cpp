#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int a = 100;
  int *ptr = &a; // Asteric is important to store the address, without this we cannot store the address.

  // int p = &a; //this is wrong

  cout << ptr << endl;  // this variable print the addresss...
  cout << *ptr << endl; // this give the value which is present in the address of &a or ptr

  float pi = 3.14;
  float *ptr1 = &pi;
  cout << ptr1 << endl;
  cout << *ptr1 << endl;

  cout << sizeof(ptr) << endl;
  cout << sizeof(ptr1) << endl;

  return 0;
}