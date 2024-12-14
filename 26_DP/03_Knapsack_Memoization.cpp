#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &val, vector<int> &wt, int w, int n, vector<vector<int>> &dp) {
  if (n == 0 || w == 0)
    return 0;

  if (dp[n][w] != -1) {
    return dp[n][w];
  }

  if (wt[n - 1] <= w) {
    int include = val[n - 1] + solve(val, wt, w - wt[n - 1], n - 1, dp);
    int exclude = solve(val, wt, w, n - 1, dp);
    return dp[n][w] = max(include, exclude);
  }

  return dp[n][w] = solve(val, wt, w, n - 1, dp);
}

int main() {
  // code here
  vector<int> val = {15, 14, 10, 45, 30};
  vector<int> wt = {2, 5, 1, 3, 4};
  int w = 7;

  int n = val.size();

  vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

  cout << solve(val, wt, w, n, dp) << endl;

  for(int i = 0; i<n+1; i++){
    for(int j=0; j<w+1; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}