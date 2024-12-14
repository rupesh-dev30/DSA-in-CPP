#include <bits/stdc++.h>
using namespace std;

int targetSum(vector<int> &nums, int target, int n, vector<vector<int>> &dp) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= target; j++) {
      if (nums[i - 1] <= j) {
        dp[i][j] = max(nums[i-1] + dp[i - 1][j - nums[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][target] == target;
}

int main() {
  // code here
  vector<int> nums = {4, 2, 7, 1, 3};
  int target = 7;

  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  cout << targetSum(nums, target, n, dp) << endl;

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < target + 1; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return 0;

}