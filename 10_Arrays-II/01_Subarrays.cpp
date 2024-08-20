#include <bits/stdc++.h>
using namespace std;

/*
    Subarrays: Continous subarrays.
      Total subarrays: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2

// Subsequence: Non continous subarrays.

*/

void printSubarrays(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      // cout << "(" << i << "," << j << ") ";
      for (int k = i; k <= j; k++) {
        cout << arr[k];
      }
      cout << ", ";
    }
    cout << endl;
  }
}

int main() {
  // code here
  int arr[5] = {1, 2, 3, 4, 5};
  int n = 5;

  printSubarrays(arr, 5);

  return 0;
}

// Time complexitity: O(n^3)