#include <bits/stdc++.h>
using namespace std;

// O(n*m)
int lcs_memo(string str1, string str2, vector<vector<int>> &dp) {
  int n = str1.length();
  int m = str2.length();

  if (n == 0 || m == 0) {
    return 0;
  }

  if (dp[n][m] != -1) {
    return dp[n][m];
  }

  if (str1[n - 1] == str2[m - 1]) {
    dp[n][m] = 1 + lcs_memo(str1.substr(0, n - 1), str2.substr(0, m - 1), dp);
  } else {
    dp[n][m] = max(lcs_memo(str1.substr(0, n - 1), str2, dp), lcs_memo(str1, str2.substr(0, m - 1), dp));
  }

  return dp[n][m];
}

int main() {
  // code here
  string str1 = "abcd";
  string str2 = "aceb";

  int n = str1.length();
  int m = str2.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

  cout << lcs_memo(str1, str2, dp) << endl;

  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < m+1; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}