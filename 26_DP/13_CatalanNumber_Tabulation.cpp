#include <bits/stdc++.h>
using namespace std;

/*
    Catalan's Number

    C0 = 1
    C1 = 1
    C2 = (C0 * C1) + (C1 * C) = 2
    C3 = (C0 * C2) + (C1 * C1) + (C2 * C0) = 5
    C4 = (C0 * C3) + (C1 * C2) + (C2 * C1) + (C3 * C0) = 14
*/

int main() {
  // code here
  int n = 4;
  vector<int> dp(n + 1);
  
  dp[0] = dp[1] = 1;

  for(int i=2; i<=n; i++){
    for(int j=0; j<i; j++){
      dp[i] += dp[j] * dp[i-j-1]; // n -> replace to i and i replace to j
    }
  }

  cout << dp[n] << endl;

  return 0;
}