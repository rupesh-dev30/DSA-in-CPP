#include <bits/stdc++.h>
using namespace std;

// Idea : use a frequency count elements from min to max
void countingSort(int *arr, int n) {
  int freq[100000] = {0}; // range

  int minValue = INT_MAX, maxValue = INT_MIN;
  for (int i = 0; i < n; i++) {
    minValue = min(minValue, arr[i]);
    maxValue = max(maxValue, arr[i]);
  }

  for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
  }

  for (int i = minValue, j = 0; i <= maxValue; i++) {
    while (freq[i] > 0) {
      arr[j++] = i;
      freq[i]--;
    }
  }
}

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // code here
  int arr[] = {1, 4, 1, 3, 2, 4, 3, 7};
  countingSort(arr, 8);

  printArr(arr, 8);

  return 0;
}

// Time complexity: O(n+)
// Space complexity: O(K)

// The time complexity of counting sort is O(n + k), where n is the number of elements in the input array and k is the range of the input (difference between maximum and minimum values). This is because the algorithm iterates through the input array twice - once to calculate the frequency of each element and once to reconstruct the sorted array. The space complexity is O(k) for the frequency array.

// In this specific implementation, the time complexity is O(n + k) because we iterate through the input array twice - once to find the minimum and maximum values, and once to populate the frequency array. The space complexity is O(k) because the frequency array is of size k, where k is the range of the input array.
