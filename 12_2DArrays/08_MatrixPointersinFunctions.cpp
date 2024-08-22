#include <bits/stdc++.h>
using namespace std;

void matrix(int mat[][4], int n, int m) {
  cout << "0th row ptr " << mat << endl;
  cout << "1st row ptr " << mat + 1 << endl;
  cout << "2nd row ptr " << mat + 2 << endl;

  cout << endl;

  cout << "0th row value " << *mat << endl;
  cout << "1st row value " << *(mat + 1) << endl;
  cout << "2nd row value " << *(mat + 2) << endl;

  cout << endl;

  cout << *(*(mat + 2) + 2);
}

int matrixPointer(int (*mat)[4]) {
  // ...
}

int main() {
  // code here
  int mat[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};

  matrix(mat, 4, 4);

  return 0;
}

/*
    ptr[i][j] = *( * ( ptr + i ) + j )
*/