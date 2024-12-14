#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> nums, int target, int n, vector<vector<int>> dp) {
  if (n == 0 || target < 0)
    return false;
  if (target == 0)
    return true;

  if(dp[n][target] != -1) {
    return dp[n][target];
  }

  if(nums[n-1] <= target){
    bool include = solve(nums, target - nums[n-1], n-1, dp);
    bool exclude = solve(nums, target, n-1, dp);
    return dp[n][target] = include || exclude;
  } else {
    return dp[n][target] = solve(nums,target,n-1,dp);
  }
}

int main() {
  // code here
  vector<int> nums = {4, 2, 7, 1, 3};
  int target = 18;

  int n = nums.size();

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

  bool result = solve(nums,target,n,dp);
  cout << (result ? "True" : "False") << endl;

  return 0;
}