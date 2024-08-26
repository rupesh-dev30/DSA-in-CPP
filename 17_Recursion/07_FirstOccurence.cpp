#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int i, int target){
  if(arr[i] == target){
    return i;
  }

  if(i == n){
    return -1;
  }

  return firstOccurence(arr, n, i+1, target);
}

int main() {
  // code here
  int arr[] = {1,2,3,3,3,4};
  int target = 4;

  //first occurence ar index 2
  cout << firstOccurence(arr, 6, 0, target);

  return 0;
}