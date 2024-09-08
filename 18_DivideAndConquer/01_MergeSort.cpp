#include <bits/stdc++.h>
using namespace std;

/*
    Divide and Rules:
*/

void merge(int arr[], int s, int mid, int e) {
  vector<int> temp;
  int i = s;
  int j = mid + 1;

  while (i <= mid && j <= e) {
    if (arr[i] <= arr[j]) {
      temp.push_back(arr[i++]);
    } else {
      temp.push_back(arr[j++]);
    }
  }

  while (i <= mid) {
    temp.push_back(arr[i++]);
  }

  while (j <= e) {
    temp.push_back(arr[j++]);
  }

  // vector -> org
  for (int i = s, x = 0; i <= e; i++) { // original array
    arr[i] = temp[x++];
  }
}

void mergeSort(int arr[], int s, int e) {
  if (s >= e) {
    return;
  }
  
  int mid = s + (e - s) / 2;

  // Left
  mergeSort(arr, s, mid);

  // Right
  mergeSort(arr, mid + 1, e);

  // merge
  merge(arr, s, mid, e);
}

int main() {
  // code here
  int arr[6] = {6, 3, 7, 5, 2, 4};

  int n = 6;

  mergeSort(arr, 0, n - 1);

  for(int i=0; i<6; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}