#include <bits/stdc++.h>
using namespace std;

/*
    Find count of all possible structurally unique BSTs (Binary Search Trees) that can be formed with n nodes

    n = 0
    output = 1

    n = 1
    output = 1

    n = 2
    output = 2

    n = 3
    output = 5

    n = 4
    output = 14
*/

int main() {
  // code here
  int n = 4;
  vector<int> dp(n + 1);

  dp[0] = dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1]; // n -> replace to i and i replace to j
    }
  }

  cout << dp[n] << endl;

  return 0;
}