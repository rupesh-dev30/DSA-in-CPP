#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void changeArr(int arr[], int n, int index) {
  if(index == n) {
    printArr(arr, n);
    return;
  }

  arr[index] = index + 1;
  changeArr(arr, n, index + 1);
  arr[index] -= 2;
}

int main() {
  // code here
  int arr[5] = {0};
  int n = 5;

  changeArr(arr, n, 0);

  printArr(arr, n);

  return 0;
}