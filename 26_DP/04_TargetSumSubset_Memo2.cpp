#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> nums, int target, int n, vector<vector<int>> dp, int temp) {
  if(temp == target) return true;

  if(n == 0 || temp < target) return false;

  if(dp[n][target] != -1) {
    return dp[n][target];
  }

  if(nums[n-1] <= temp){
    bool ans = solve(nums, target, n-1, dp, temp - nums[n-1]);
    dp[n][target] = ans;
    return ans;
  } else {
    bool ans = solve(nums, target, n-1, dp, temp);
    dp[n][target] = ans;
    return ans;
  }
}

int main() {
  // code here
  vector<int> nums = {4, 2, 7, 1, 3};
  int target = 7;

  int n = nums.size();

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

  bool result = solve(nums,target,n,dp,0);
  cout << (result ? "True" : "False") << endl;

  return 0;
}