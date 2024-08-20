#include <bits/stdc++.h>
using namespace std;

// Brute force approach
int maxSubArraySum(int arr[], int n) {
  int maxi = INT_MIN;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int temp = 0;
      for (int k = i; k <= j; k++) {
        temp += arr[k];
      }
      maxi = max(temp, maxi);
    }
  }
  return maxi;
}

int main() {
  // code here
  int arr[] = {2, -3, 6, -5, 4, 2};

  cout << "Max subarrays sum is: " << maxSubArraySum(arr, 6);

  return 0;
}

// Time complexity: O(n^3)
// Space complexity: O(1)

//The time complexity of the brute force approach for finding the maximum subarray sum is O(n^3), where n is the size of the input array. This is because there are three nested loops iterating over the array elements, resulting in a cubic time complexity.

// The space complexity of the brute force approach is O(1) because it only uses a constant amount of extra space for storing variables like `maxi`, `temp`, and loop counters.