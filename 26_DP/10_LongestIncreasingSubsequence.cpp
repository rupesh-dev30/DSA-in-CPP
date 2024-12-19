#include <bits/stdc++.h>
using namespace std;

/*
    STEPS:

      1. Copy array -> uniquely
      2. Sort array -> ascending

      LCS => LIS comparing

*/

int solve(vector<int> arr) {
  unordered_set<int> s(arr.begin(), arr.end());

  // for (int el : arr) {
  //   s.insert(el);
  // }

  vector<int> arr2(s.begin(), s.end());

  // for(int el : s){
  //   arr2.push_back(el);
  // }

  sort(arr2.begin(), arr2.end());

  int n = arr.size();
  int m = arr2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (arr[i - 1] == arr2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  // code here
  vector<int> arr = {50, 3, 10, 7, 40, 80};

  cout << solve(arr) << endl;

  return 0;
}