#include <bits/stdc++.h>
using namespace std;

// Number of column must be initialised
void spiralMatrix(int matrix[][4], int n, int m) {
  int sRow = 0, eRow = n - 1, sCol = 0, eCol = m - 1;

  while (sRow <= eRow && sCol <= eCol) {
    // for square matrix we can use ||  but for rectangle matrix we must use &&

    // Top
    for (int j = sCol; j <= eCol; j++) {
      cout << matrix[sRow][j] << " ";
    }

    // Right
    for (int i = sRow + 1; i <= eRow; i++) {
      cout << matrix[i][eCol] << " ";
    }

    // Bottom
    for (int j = eCol - 1; j >= sCol; j--) {
      cout << matrix[eRow][j] << " ";
    }

    // Left
    for (int i = eRow - 1; i >= sRow + 1; i--) {
      cout << matrix[i][sCol] << " ";
    }

    sRow++;
    eRow--;
    sCol++;
    eCol--;
  }
}

int main() {
  // code here
  int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  spiralMatrix(arr, 4, 4);

  return 0;
}