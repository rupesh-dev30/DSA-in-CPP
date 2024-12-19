#include <bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int n, int m, vector<vector<int>> &dp, int &ans) {
  if (n == 0 || m == 0) {
    return 0;
  }

  if (dp[n][m] != -1) {
    return dp[n][m];
  }

  if (str1[n - 1] == str2[m - 1]) {
    dp[n][m] = 1 + solve(str1, str2, n - 1, m - 1, dp, ans);
    ans = max(ans, dp[n][m]);
  } else {
    dp[n][m] = 0;
  }
  solve(str1, str2, n - 1, m, dp, ans);
  solve(str1, str2, n, m - 1, dp, ans);

  return dp[n][m];
}

int main() {
  // code here
  string str1 = "abcde";
  string str2 = "agabce";

  int n = str1.length();
  int m = str2.length();

  int ans = 0;

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

  cout << solve(str1, str2, n, m, dp, ans) << endl;

  return 0;
}


/// ERRRRRRRRRROOOOOOOOOOOOORRRRRRRRRRR