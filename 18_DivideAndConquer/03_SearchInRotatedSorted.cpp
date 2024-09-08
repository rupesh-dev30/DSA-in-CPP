#include <bits/stdc++.h>
using namespace std;

/*

  Input: Rotated, sorted array with distinct nums; ascending order

  Example:                       0, 1, 2, 4, 5, 6, 7
  Pivot = 2 (rotate around 2):   4, 5, 6, 7, 0, 1, 2


  approach 1: Linear Search
  approach 2: Modified Binary Search

*/

int search(int arr[], int s, int e, int target) {
  if(s > e) {
    return -1;
  }
  
  int mid = s + (e - s) / 2;

  if (arr[mid] == target) {
    return mid;
  }

  if (arr[s] <= arr[mid]) {
    if (arr[s] <= target && target < arr[mid]) {
      // left half
      return search(arr, s, mid - 1, target);
    } else {
      // right half
      return search(arr, mid + 1, e, target);
    }
  } else {
    // right half
    if (arr[mid] < target && target <= arr[e]) {
      return search(arr, mid + 1, e, target);
    } else {
      // left half
      return search(arr, s, mid - 1, target);
    }
  }
}

int main() {
  // code here
  int arr[] = {4, 5, 6, 7, 0, 1, 2};
  int size = 7;

  cout << search(arr, 0, size - 1, 0);

  return 0;
}

/*
  LEETCODE PROBLEM:
    81, 153, 175
*/