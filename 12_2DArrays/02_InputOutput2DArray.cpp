#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int arr[3][4];

  // Input
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
    }
  }

  // Output
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
    2D arrays in Memory

      - 2D array is represented as a contiguous block of memory cells (linearly)


      Row Major (default) : 
          R1        R2        R3
        {1,2,3} , {4,5,6}, {7,8,9}

      Column Major : 
          C1        C2       C3
        {1,2,3} , {4,5,6}, {7,8,9}
*/