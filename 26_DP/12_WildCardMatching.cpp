#include <bits/stdc++.h>
using namespace std;

/*
    Wildcard Matching

      Find if wildcard pattern can be matched with a text. The wildcard pattern can include the characters '?' and '*'

      '?' - matches any single character
      '*' - matches any sequence of characters (including the empty sequence)

      Text = "baaabab"
      Pattern = "**ba****ab*"
      output = true

      Text = "baaabab"
      Pattern = "a*ab"
      output = false
*/

bool isMatch(string s, string p) {
  int n = s.length();
  int m = p.length();

  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[0][0] = true;

  for (int j = 1; j < m + 1; j++) {
    if (p[j - 1] == '*') {
      dp[0][j] = dp[0][j - 1];
    } else {
      dp[0][j] = false;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (p[j - 1] == '*') {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      } else {
        dp[i][j] = false;
      }
    }
  }
  return dp[n][m];
}

int main() {
  // code here
  string str1 = "baaabab";
  string str2 = "**ba****ab*";

  if(isMatch(str1, str2)){
    cout << "Matched" << endl;
  } else {
    cout << "Not Matched" << endl;
  }

  return 0;
}