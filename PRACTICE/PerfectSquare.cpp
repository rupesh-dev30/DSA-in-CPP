#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp) {
  if(n == 0) return 0;

  if(dp[n] != -1) return dp[n];

  int minCount = INT_MAX;

  for(int i=1; i*i <= n; i++) {
    int result = 1 + solve(n - (i*i), dp);
    minCount = min(result,minCount);
  }
  return dp[n] = minCount;
}

int numSquares(int n) {
  vector<int> dp(n+1, -1);

  return solve(n,dp);
}

int main() {
  // code here
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;
    cout << numSquares(n);
  }

  cout << endl;

  return 0;
}