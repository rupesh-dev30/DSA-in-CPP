#include <bits/stdc++.h>
using namespace std;

// Slightly approach version of max subarrays sum
int maxSubArraySum(int arr[], int n) {
  int maxi = INT_MIN;
  for(int i=0; i<n; i++){
    int temp = 0;
    for(int j=i; j<n; j++){
      temp += arr[j];
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

// Time complexity: O(n^2)
// Space complexity: O(1)

// The time complexity of the maxSubArraySum function is O(n^2) because there are two nested loops iterating over the array elements. The outer loop runs n times, and for each iteration of the outer loop, the inner loop runs n-i times, where i is the current index of the outer loop. This results in a total of n*(n+1)/2 iterations, which simplifies to O(n^2) in terms of time complexity.

// The space complexity of the function is O(1) because it only uses a constant amount of extra space regardless of the size of the input array.
