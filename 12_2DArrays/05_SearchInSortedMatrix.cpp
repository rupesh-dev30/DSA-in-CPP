#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m) => O(n^2)
bool searchIn2dMatrix(int arr[][4], int n, int key){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j]==key){
        return true;
      }
    }
  }
  return false;
}

int main() {
  // code here
  int arr[4][4] = {
      {10, 20, 30, 40},
      {15, 25, 35, 45},
      {17, 29, 37, 48},
      {32, 33, 39, 50},
  };

  if (searchIn2dMatrix(arr, 4, 39)) {
    cout << "Element is present in the matrix" << endl;
  } else {
    cout << "Element is not present in the matrix" << endl;
  };

  return 0;
}