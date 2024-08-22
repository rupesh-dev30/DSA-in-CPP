#include <bits/stdc++.h>
using namespace std;

// Matrix must be sorted row wise and col wise

// Time Complexity: O(n + m) => ~ O(n)
bool searchIn2dMatrix(int matrix[][4], int n, int m, int key) {
  int i = 0, j = m - 1;
  
  while(i<n && j >= 0){
    if(matrix[i][j] == key){
      return true;
    } else if (matrix[i][j] > key) {
      j--;
    } else {
      i++;
    }
  }
  return false;
}

int main() {
  // code here
  int arr[4][4] = {
      {10, 20, 30, 40},
      {15, 25, 35, 45},
      {17, 29, 37, 48},
      {32, 33, 39, 50},
  };

  if (searchIn2dMatrix(arr, 4, 4, 60)) {
    cout << "Element is present in the matrix" << endl;
  } else {
    cout << "Element is not present in the matrix" << endl;
  };

  return 0;
}