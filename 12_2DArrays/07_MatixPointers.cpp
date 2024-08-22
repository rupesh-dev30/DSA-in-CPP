#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int arr[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  cout << arr << endl;  // first row
  cout << &arr[0][0] << endl;
  /*
      In Array: when we add + 1 then it point to next element in that array ( x + 4)

      In 2D Array: when we add + 1 then it point to next row. (above example ( x + 16))
  */

  cout << arr + 1 << endl;  // second row
  cout << &arr[1][0] << endl;  // second row
  cout << &arr[0][1] << endl;  // second element of 1st row

  return 0;
}


// 2D Array name behaves as a row pointer