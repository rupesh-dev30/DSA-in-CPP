#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(vector<int> &nums) {
  int n = nums.size();

  vector<unordered_map<ll,int>> dp(n);
  int totalCount = 0;

  for(int i=1; i<n; i++) {
    for(int j=0; j<i; j++) {
      ll diff = (ll)nums[i] - nums[j];
      int count = dp[j].count(diff) ? dp[j][diff] : 0;

      dp[i][diff] += count + 1;
      totalCount += count;
    }
  }
  return totalCount;
}

int main() {
  // code here
  vector<int> nums = {2,4,6,8,10};

  cout << solve(nums) << endl;

  return 0;
}