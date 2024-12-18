#include <bits/stdc++.h>
using namespace std;

// Cut rod into pieces to get maxProfit from pieces. Possible pieces are always of len 1 to n
int rodCutting(vector<int> price, vector<int> length, int rodLength, int n, vector<vector<int>> &dp) {
  if (n == 0 || rodLength == 0) {
    return 0;
  }

  if (dp[n][rodLength] != -1) {
    return dp[n][rodLength];
  }

  if (length[n - 1] <= rodLength) {
    return dp[n][rodLength] = max(price[n - 1] + rodCutting(price, length, rodLength - length[n - 1], n, dp), rodCutting(price, length, rodLength, n - 1, dp));
  }
  return dp[n][rodLength] = rodCutting(price, length, rodLength, n, dp);
}

int main() {
  // code here
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
  int rodLength = 8;

  int n = length.size();

  vector<vector<int>> dp(n + 1, vector<int>(rodLength + 1, -1));

  cout << rodCutting(price, length, rodLength, n, dp) << endl;

  return 0;
}