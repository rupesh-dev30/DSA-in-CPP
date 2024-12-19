#include <bits/stdc++.h>
using namespace std;

/*
  Substring is a contiguous sequence of characters within a string

  str1 = "abcde"
  str2 = "abgce"

  lcs = 2 //"ab"
*/

int main() {
  // code here
  string str1 = "abcde";
  string str2 = "agabce";

  int n = str1.length();
  int m = str2.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int ans = 0;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(dp[i][j], ans);
      } else {
        dp[i][j] = 0;
      }
    }
  }

  cout << ans << endl;

  return 0;
}