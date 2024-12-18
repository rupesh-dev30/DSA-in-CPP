#include <bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2) {
  int n = str1.length();
  int m = str2.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if(str1[i-1] == str2[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  // code here
  string str1 = "abcd";
  string str2 = "aced";
  cout << lcs(str1, str2) << endl;

  return 0;
}