#include <bits/stdc++.h>
using namespace std;

// Cut rod into pieces to get maxProfit from pieces. Possible pieces are always of len 1 to n
int rodCutting(vector<int> price, vector<int> length, int rodLength) {
  int n = length.size();
  vector<vector<int>> dp(n + 1, vector<int>(rodLength + 1, 0));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < rodLength + 1; j++) {
      if (length[i - 1] <= j) {
        dp[i][j] = max(dp[i][j - length[i - 1]] + price[i - 1], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][rodLength];
}

int main() {
  // code here
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
  int rodLength = 8;

  cout << rodCutting(price, length, rodLength) << endl;

  return 0;
}