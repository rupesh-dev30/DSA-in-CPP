#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> coins, int amount) {
  int n = coins.size();
  vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 1;
  }

  for(int i=1; i<n+1; i++){
    for(int j=1; j<amount+1; j++){
      if(coins[i-1] <= j){
        int include = dp[i][j - coins[i-1]];
        int exclude = dp[i-1][j];
        dp[i][j] = include + exclude;
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][amount];
}

int main() {
  // code here
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  cout << solve(coins, amount) << endl;
  // solve(coins, amount);


  return 0;
}