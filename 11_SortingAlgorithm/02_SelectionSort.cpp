#include <bits/stdc++.h>
using namespace std;

// Pick the smallest (from unsorted) & put in the beginning
void selectionSort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
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
  int arr[] = {5, 4, 1, 3, 2};
  selectionSort(arr, 5);

  printArr(arr, 5);

  return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(1)

// The time complexity of selection sort is O(n^2) in the worst case, as there are two nested loops iterating over the array elements. The space complexity is O(1) as the algorithm sorts the array in place without using any additional space.