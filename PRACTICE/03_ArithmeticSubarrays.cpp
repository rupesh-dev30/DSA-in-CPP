#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
  int n = nums.size();
  if (n < 3)
    return 0;

  int total = 0, count = 0;

  for (int i = 2; i < n; i++) {
    if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
      count++;
      total += count;
    } else {
      count = 0;
    }
  }
  return total;
}

int main() {
  // code here
  vector<int> nums = {1, 2, 3, 4};
  cout << "Numbre of arithmetic subarrays: " << solve(nums) << endl;

  return 0;
}