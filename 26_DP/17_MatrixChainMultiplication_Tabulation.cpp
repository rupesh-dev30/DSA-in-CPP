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

int matrixMultiplication(vector<int> arr) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 1; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int len = 2; len < n; len++) {
    for (int i = 1; i <= n - len; i++) {
      int j = i + len - 1;

      dp[i][j] = INT_MAX;

      for (int k = i; k < j; k++) {
        int cost1 = dp[i][k];
        int cost2 = dp[k + 1][j];
        int currentCost = cost1 + cost2 + (arr[i - 1] * arr[k] * arr[j]);
        dp[i][j] = min(dp[i][j], currentCost);
      }
    }
  }

  return dp[1][n-1];
}

int main() {
  // code here
  vector<int> arr = {1, 2, 3, 4, 3};

  cout << matrixMultiplication(arr) << endl;

  return 0;
}