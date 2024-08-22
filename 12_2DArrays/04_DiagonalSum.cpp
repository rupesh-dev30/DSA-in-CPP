#include <bits/stdc++.h>
using namespace std;

int diagonalSum(int arr[][4], int n) {
  int sum = 0;

  /*

  // Time Complexities: O(n^2)
  // Worst Case

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        sum += arr[i][j];
      } else if (j == n - i - 1) {
        sum += arr[i][j];
      }
    }
  }

  */


  // Time Complexities: O(n)
  // Optimized Code
  for (int i = 0; i < n; i++) {
    sum += arr[i][i];  // primary diagonal
    if(i != n-i-1){
      sum += arr[i][n-i-1];  // secondary diagonal
    }
  }

  return sum;
}

int main() {
  // code here
  int arr[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};

  // Primary Diagonal : 1 , 6, 11, 16
  // Secondary Diagonal: 4 , 7, 10, 13

  cout << " sum of diagonal element is : " << diagonalSum(arr, 4) << endl;

  int arr2[3][3] = {
      {1, 2, 3},
      {5, 6, 7},
      {9, 10, 11}};

  // Primary Diagonal : 1, 6, 11
  // Secondary Diagonal: 3, 6, 9       Dupicate (6) : ODD: Middle element come twice

  // cout << " sum of diagonal element is : " << diagonalSum(arr2, 3) << endl;

  return 0;
}