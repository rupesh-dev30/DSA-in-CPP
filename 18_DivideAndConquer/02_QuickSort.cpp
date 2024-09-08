#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e) {
  int i = s - 1;
  int pivot = arr[e];

  for(int j=s; j<e; j++){
    if(arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  i++;
  swap(arr[i], arr[e]);
  // pivot index = i
  return i;
}

void quickSort(int arr[], int s, int e){
  if(s >= e) {
    return;
  }

  int pivotIndex =  partition(arr,s,e);

  quickSort(arr, s, pivotIndex-1); // Left Half
  quickSort(arr, pivotIndex+1, e); // Right Half
}

int main() {
  // code here
  int arr[6] = {6, 3, 7, 5, 2, 4};

  int n = 6;

  quickSort(arr, 0, n - 1);

  for(int i=0; i<6; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}