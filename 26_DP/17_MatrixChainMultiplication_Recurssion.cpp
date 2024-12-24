#include <bits/stdc++.h>
using namespace std;

/*
    MATRIX CHAIN MULTIPLICATION

    Find minimum cost to multiply all matrices. Cost is no. of ops for multiplication.

    arr[n] = {1,2,3,4,3} -> matrix size
     n = 5 means n-1 = 4 matrices

    A1 = 1x2 -> arr[i-1] x arr[i]
    A2 = 2x3
    A3 = 3x4
    A4 = 4x3

    Example:
    A = 1 x 3 , B = 3 x 5 , C = 5 x 6

    ((AB)C) = 1*3*5 + 1*5*6 = 15 + 30 = 45
    (A(BC)) = 3*5*6 + 1*3*6 = 90 + 18 = 108

*/

int matrixMultiplication(vector<int> arr, int i, int j) {
  if (i == j) {
    return 0;
  }

  int ans = INT_MAX;

  for(int k=i; k<j; k++){
    int cost1 = matrixMultiplication(arr,i,k);
    int cost2 = matrixMultiplication(arr,k+1,j);

    int currentCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
    ans = min(ans,currentCost);
  }
  return ans;
}

int main() {
  // code here
  vector<int> arr = {1, 2, 3, 4, 3};
  int n = arr.size();

  cout << matrixMultiplication(arr,1,n-1) << endl;

  return 0;
}