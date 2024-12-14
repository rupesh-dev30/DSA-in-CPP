#include <bits/stdc++.h>
using namespace std;

// Return number of combinations
int solve(vector<int> coins, int n, int amount, vector<vector<int>> dp) {
  if (amount == 0) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }

  if (dp[n][amount] != -1) {
    return dp[n][amount];
  }

  if (coins[n - 1] <= amount) {
    int include = solve(coins, n, amount - coins[n - 1], dp);
    int exclude = solve(coins, n - 1, amount, dp);
    dp[n][amount] = include + exclude;
  } else {
    dp[n][amount] = solve(coins, n - 1, amount, dp);
  }
  return dp[n][amount];
}

int main() {
  // code here
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  int n = coins.size();
  vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

  cout << solve(coins, n, amount, dp) << endl;

  return 0;
}

/*
  example:
  coins[] = {1,2,5} , amount: 5

  total number of ways: (1+1+1+1+1), (1+1+1+2), (1+2+2), (5)
  answer : 4
*/