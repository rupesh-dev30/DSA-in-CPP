#include <bits/stdc++.h>
using namespace std;

int lastOccurence(int arr[], int i, int target) {
  if(arr[i] == target){
    return i;
  }

  if(i == -1){
    return -1;
  }

  return lastOccurence(arr, i-1, target);
}

int lastOccurence2(int arr[], int n, int i, int target ){
  if(i == n){
    return -1;
  }

  int indexFound = lastOccurence2(arr, n, i+1, target);
  if(indexFound == -1){
    if(arr[i] == target){
      return i;
    }
  }
  return indexFound;
}

int main() {
  // code here
  int arr[] = {1,2,3,3,3,4};
  int size = 6;
  int target = 3;

  //first occurence ar index 2
  cout << lastOccurence(arr, 5, target) << endl;
  cout << lastOccurence2(arr, 6, 0, target);

  return 0;
}