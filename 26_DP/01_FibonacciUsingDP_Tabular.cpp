#include <bits/stdc++.h>
using namespace std;

// Fibonacci with tabulation (loops)
// Bottom up approach

int main() {
  // code here
  int n = 6;
  vector<int> dp(n+1, 0);
  dp[1] = 1;

  for(int i=2; i<n+1; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  cout << dp[n];
  return 0;
}