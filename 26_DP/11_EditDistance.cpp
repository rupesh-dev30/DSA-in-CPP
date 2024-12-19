#include <bits/stdc++.h>
using namespace std;

/*
    EDIT DISTANCE

    For 2 strings, return minimum number of operations to convert str1 to str2

    1.  str1 = "abc"
        str2 = "ac"
        ops = 1    // delete 'b

    2.  str1 = "horse"
        str2 = "ros"
        ops = 3  //replace "h" with "r" and delete "r" & "e"

*/

int minDistance(string word1, string word2) {
  int n = word1.length();
  int m = word2.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int j = 1; j < m + 1; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i < n + 1; i++) {
    dp[i][0] = i;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // delete , insert, replace
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
      }
    }
  }
  return dp[n][m];
}

int main() {
  // code here
  string word1 = "horse";
  string word2 = "ros";
  cout << minDistance(word1, word2) << endl;

  return 0;
}