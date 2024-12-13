#include <bits/stdc++.h>
using namespace std;

// Count ways to reach the nth stair. A person can climb 1,2 or 3 stairs at a time

int main() {
  // code here
  int n = 4;

  vector<int> dp(n+1, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  
  for(int i = 3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }

  cout << dp[n] << endl;
  return 0;
}