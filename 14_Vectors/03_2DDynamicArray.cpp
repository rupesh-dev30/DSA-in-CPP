#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int rows, cols;
  cout << "Enter row : ";
  cin >> rows;
  cout << "Enter col : ";
  cin >> cols;

  int **arr = new int *[rows];

  for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }

  // store data
  int x = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = x++; //   *(*(arr + i)+j)
      cout << arr[i][j];
    }
    cout << endl;
  }

  return 0;
}