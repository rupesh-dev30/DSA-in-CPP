#include <bits/stdc++.h>
using namespace std;

// Pick an element from unsorted part & place it correctly in sorted part
void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int curr = arr[i];
    int prev = i - 1;

    while (prev >= 0 && arr[prev] > curr) {
      swap(arr[prev], arr[prev + 1]);
      prev--;
    }

    arr[prev] = curr;
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
  insertionSort(arr, 5);

  printArr(arr, 5);

  return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(1)

// The time complexity of the insertion sort algorithm is O(n^2) in the worst-case scenario, where n is the number of elements in the array. This is because in the worst case, for each element in the array, we may need to compare it with and potentially swap it with every element before it.

// The space complexity of the insertion sort algorithm is O(1) because it only requires a constant amount of extra space for storing variables like the current element being sorted and the index of the previous element being compared.

// Overall, insertion sort is an efficient algorithm for small input sizes or nearly sorted arrays, but it may not be the best choice for large input sizes due to its quadratic time complexity.