#include <bits/stdc++.h>
using namespace std;

/*
    Using up and down strokes create mountains. Find total number of mountains with n pairs of up and down strokes.
    (at any moment number of downstrokes can't be more than upstrokes)

    pairs = 3 means  / \ , / \ , / \
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