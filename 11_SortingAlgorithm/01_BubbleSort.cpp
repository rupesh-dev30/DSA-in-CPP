#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n) {
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

int main() {
  // code here
  int arr[] = {8,6,7,9,4,3,5,1,2};
  int size = 8;

  bubbleSort(arr, size);

  for(int i=0; i<size; i++){
    cout << arr[i] << " ";
  }

  return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(1)

// The time complexity of the bubble sort algorithm is O(n^2) in the worst-case scenario, where n is the number of elements in the array. This is because there are two nested loops, and in the worst case, the inner loop will run n-1 times for each iteration of the outer loop.

// The space complexity of the bubble sort algorithm is O(1) because it only requires a constant amount of extra space for storing temporary variables. No additional space is required based on the input size.
