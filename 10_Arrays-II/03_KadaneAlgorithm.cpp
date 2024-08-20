#include <bits/stdc++.h>
using namespace std;

// Kadane algorithm is DP problem
// Optimized version of Maximum subarray sum

int maxSubArraySum(int *arr, int n) {
  int currSum = 0;
  int maxSum = INT_MIN;

  for (int i = 0; i < n; i++) {
    currSum += arr[i];
    maxSum = max(currSum, maxSum);

    if (currSum < 0) {
      currSum = 0;
    }
  }
  return currSum;
}

int main() {
  // code here
  int arr[] = {2, -3, 6, -5, 4, 2};

  cout << "Maximum subarray sum is : " << maxSubArraySum(arr, 6);

  return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)

// The time complexity of the Kadane's algorithm is O(n) because it iterates through the array only once. The space complexity is O(1) because it uses only a constant amount of extra space regardless of the input size. This is because it does not use any additional data structures that grow with the input size.