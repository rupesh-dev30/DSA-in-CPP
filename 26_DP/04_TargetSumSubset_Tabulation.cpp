#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  vector<int> nums = {4, 2, 7, 1, 3};
  int target = 19;

  int n = nums.size();

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  for(int i=0; i<n+1; i++) {
    dp[i][0] = 1;
  }

  for(int i=1; i<n+1; i++){
    for(int j=1; j<target+1; j++){
      if(nums[i-1] <= target) {
        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[n][target] << endl;

  for(int i = 0; i<n+1; i++){
    for(int j=0; j<target+1; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}