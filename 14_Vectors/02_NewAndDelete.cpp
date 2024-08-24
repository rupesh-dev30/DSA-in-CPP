/*
    Dynamic Memory Allocation in C++

    Dynamic memory allocation allows you to allocate memory at runtime using pointers. This is useful when the amount of memory needed cannot be determined at compile time.


// Key Functions:

    // 1. `new`: Allocates memory for a variable or array at runtime.

    int* ptr = new int;    // Allocates memory for a single integer
    int* arr = new int[10]; // Allocates memory for an array of 10 integers

    // 2. `delete`: Deallocates memory that was previously allocated with new. This prevents memory leaks.

    delete ptr;       // Deletes the memory allocated for a single integer
    delete[] arr;     // Deletes the memory allocated for an array

*/

// example:

#include <iostream>
using namespace std;

void func() {
  int size;
  cin >> size;

  int *ptr = new int[size];

  int x = 1;
  for (int i = 0; i < size; i++) {
    ptr[i] = x;
    cout << ptr[i] << " ";
    x++;
  }
  cout << endl;

  delete[] ptr; // space free
}

int main() {
  func();

  return 0;
}
