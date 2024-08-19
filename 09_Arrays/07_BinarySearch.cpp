#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int n, int key) {
  int low = 0, high = n - 1;
  int mid = low + (high - low) / 2;

  while (low <= high) {
    if (arr[mid] == key)
      return true;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
    mid = low + (high - low) / 2;
  }
  return false;
}

int main() {
  // code here
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = 11;

  if (binarySearch(arr, 10, key)) {
    cout << "Element found in array" << endl;
  } else {
    cout << "Element not found in array" << endl;
  }

  return 0;
}

// Time complexities: log(n)
// Space complexities: O(1)