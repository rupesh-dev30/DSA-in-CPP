#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  vector<int> val = {6, 1, 7, 7};
  vector<int> wt = {1, 3, 4, 5};
  int w = 8;

  int n = val.size();

  vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

  for(int i=1; i<=n; i++){
    for(int j=1; j<=w; j++) {
      if(wt[i-1] <= j) {
        int include = val[i-1] + dp[i][j-wt[i-1]];
        int exclude = dp[i-1][j];
        dp[i][j] = max(include,exclude);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[n][w] << endl;

  for(int i = 0; i<n+1; i++){
    for(int j=0; j<w+1; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}