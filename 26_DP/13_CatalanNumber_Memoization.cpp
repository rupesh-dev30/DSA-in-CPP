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

int Catalan(int n, vector<int> &dp) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if(dp[n] != -1){
    return dp[n];
  }

  int res = 0;

  for (int i = 0; i < n; i++) {
    res += Catalan(i, dp) * Catalan(n - i - 1, dp);
  }

  return dp[n] = res;
}

int main() {
  // code here
  int n = 4;
  vector<int> dp(n + 1, -1);
  cout << Catalan(n, dp) << endl;

  return 0;
}