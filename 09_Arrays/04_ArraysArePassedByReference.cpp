#include <bits/stdc++.h>
using namespace std;

void changeValue(int arr[]) {
  arr[0] = 1000;
}

void sizeArr(int nums[]) {
  cout << sizeof(nums) << endl;
}

int main() {
  // code here
  int a = 5;
  int *ptr = &a;
  cout << ptr << endl;

  int arr[] = {1, 2, 3, 4, 5};
  // cout << sizeof(arr) / sizeof(int) << endl;
  cout << arr << endl;
  cout << *arr << endl;       // arr[0]
  cout << *(arr + 1) << endl; // arr[1]
  cout << *(arr + 2) << endl; // arr[2]
  cout << *(arr + 3) << endl; // arr[3]
  cout << *(arr + 4) << endl; // arr[4]

  changeValue(arr);
  cout << arr[0] << endl;

  cout << sizeof(arr) << endl;
  sizeArr(arr);

  return 0;
}

/*
    Arrays are passed by reference

      void printArr(int arr[]) {...}

      void printArr(int* arr) {...}

      both are same


      Array name -> Pointer 😅🤔


      NOTE: When we pass an array to the other function , then it size change to pointer size . because array is passed by referece, means its pointer address is passed. So when you passed the array to other function , always pass the size , dont try to calculate there.
*/