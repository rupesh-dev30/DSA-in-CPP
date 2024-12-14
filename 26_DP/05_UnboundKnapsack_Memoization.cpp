#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> val, vector<int> wt, int n, int capacity, vector<vector<int>> dp) {
  if (n == 0 || capacity == 0) {
    return 0;
  }

  if (dp[n][capacity] != -1) {
    return dp[n][capacity];
  }

  if (wt[n - 1] <= capacity) {
    int include = val[n - 1] + solve(val, wt, n, capacity - wt[n - 1], dp);
    int exclude = solve(val, wt, n - 1, capacity, dp);
    dp[n][capacity] = max(include, exclude);
  } else {
    dp[n][capacity] = solve(val, wt, n - 1, capacity, dp);
  }

  return dp[n][capacity];
}

int main() {
  // code here
  vector<int> val = {15, 14, 10, 45, 30};
  vector<int> wt = {2, 5, 1, 3, 4};
  int n = val.size();
  int capacity = 7;

  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
  cout << solve(val, wt, n, capacity, dp) << endl;

  return 0;
}