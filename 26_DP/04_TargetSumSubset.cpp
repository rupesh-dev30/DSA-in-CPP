#include <bits/stdc++.h>
using namespace std;

// FInd if there is a subset of numbers which give sum equal to target
bool solve(vector<int> nums, int target, int n) {
  if(target == 0) {
    return true;
  }

  if(n == 0 || target < 0) {
    return false;
  }

  if(nums[n-1] <= target) {
    bool include = solve(nums, target - nums[n-1], n-1);
    bool exclude = solve(nums, target, n-1);
    return (include || exclude);
  } else {
    return solve(nums, target, n-1);
  }
}

int main() {
  // code here
  vector<int> nums = {4,2,7,1,3};
  int target = 18;

  int n = nums.size();
  bool res = solve(nums, target, n);
  cout << (res ? "True" : "False") << endl;

  return 0;
}