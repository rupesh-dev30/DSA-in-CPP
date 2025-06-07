/*
    Segment Tree on a 2D matrix

     Use case:
        Query submatrix sum/min/max: (x1, y1) to (x2, y2)

        Competitive Programming: Grid-based problems


    Complexity:
        Build: O(n * m * 4)

        Query/Update: O(log n * log m)


  * How it Works Conceptually:

      1. For each row, build a segment tree over columns

      2. Then build a segment tree over rows, where each node stores a segment tree of its row-range


*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

int n, m;
int matrix[MAXN][MAXM];
int segment[4 * MAXN][4 * MAXM]; // 2D SEGMENT TREE

// BUILD Y-AXIS SEGMENT TREE FOR A GIVEN X NODE
void buildY(int nodeX, int rowStart, int rowEnd, int nodeY, int colStart, int colEnd) {
  if (colStart == colEnd) {
    if (rowStart == rowEnd) {
      segment[nodeX][nodeY] = matrix[rowStart][colStart];
    } else {
      segment[nodeX][nodeY] = segment[2 * nodeX][nodeY] + segment[2 * nodeX + 1][nodeY];
    }
  } else {
    int midCol = (colStart + colEnd) / 2;
    buildY(nodeX, rowStart, rowEnd, 2 * nodeY, colStart, midCol);
    buildY(nodeX, rowStart, rowEnd, 2 * nodeY + 1, midCol + 1, colEnd);
    segment[nodeX][nodeY] = segment[nodeX][2 * nodeY] + segment[nodeX][2 * nodeY + 1];
  }
}

// BUILD X-AXIS SEGMENT TREE (ROWS)
void buildX(int nodeX, int rowStart, int rowEnd) {
  if (rowStart != rowEnd) {
    int midRow = (rowStart + rowEnd) / 2;
    buildX(2 * nodeX, rowStart, midRow);
    buildX(2 * nodeX + 1, midRow + 1, rowEnd);
  }
  buildY(nodeX, rowStart, rowEnd, 1, 0, m - 1);
}

// QUERY Y-AXIS SEGMENT TREE FOR A GIVEN X NODE
int queryY(int nodeX, int nodeY, int colStart, int colEnd, int queryColStart, int queryColEnd) {
  if (queryColStart > colEnd || queryColEnd < colStart) {
    // no overlap
    return 0;
  }
  if (queryColStart <= colStart && colEnd <= queryColEnd) {
    // complete overlap
    return segment[nodeX][nodeY];
  }
  int midCol = (colStart + colEnd) / 2;
  int leftSum = queryY(nodeX, 2 * nodeY, colStart, midCol, queryColStart, queryColEnd);
  int rightSum = queryY(nodeX, 2 * nodeY + 1, midCol + 1, colEnd, queryColStart, queryColEnd);
  return leftSum + rightSum;
}

// QUERY X-AXIS SEGMENT TREE (ROWS)
int queryX(int nodeX, int rowStart, int rowEnd, int queryRowStart, int queryRowEnd, int queryColStart, int queryColEnd) {
  if (queryRowStart > rowEnd || queryRowEnd < rowStart) {
    // no overlap
    return 0;
  }
  if (queryRowStart <= rowStart && rowEnd <= queryRowEnd) {
    // complete overlap on row axis, so query on Y axis tree
    return queryY(nodeX, 1, 0, m - 1, queryColStart, queryColEnd);
  }
  int midRow = (rowStart + rowEnd) / 2;
  int leftSum = queryX(2 * nodeX, rowStart, midRow, queryRowStart, queryRowEnd, queryColStart, queryColEnd);
  int rightSum = queryX(2 * nodeX + 1, midRow + 1, rowEnd, queryRowStart, queryRowEnd, queryColStart, queryColEnd);
  return leftSum + rightSum;
}

// UPDATE Y-AXIS SEGMENT TREE FOR A GIVEN X NODE
void updateY(int nodeX, int rowStart, int rowEnd, int nodeY, int colStart, int colEnd, int targetCol, int val) {
  if (colStart == colEnd) {
    if (rowStart == rowEnd) {
      segment[nodeX][nodeY] = val;
    } else {
      segment[nodeX][nodeY] = segment[2 * nodeX][nodeY] + segment[2 * nodeX + 1][nodeY];
    }
  } else {
    int midCol = (colStart + colEnd) / 2;
    if (targetCol <= midCol) {
      updateY(nodeX, rowStart, rowEnd, 2 * nodeY, colStart, midCol, targetCol, val);
    } else {
      updateY(nodeX, rowStart, rowEnd, 2 * nodeY + 1, midCol + 1, colEnd, targetCol, val);
    }
    segment[nodeX][nodeY] = segment[nodeX][2 * nodeY] + segment[nodeX][2 * nodeY + 1];
  }
}

// UPDATE X-AXIS SEGMENT TREE
void updateX(int nodeX, int rowStart, int rowEnd, int targetRow, int targetCol, int val) {
  if (rowStart != rowEnd) {
    int midRow = (rowStart + rowEnd) / 2;
    if (targetRow <= midRow) {
      updateX(2 * nodeX, rowStart, midRow, targetRow, targetCol, val);
    } else {
      updateX(2 * nodeX + 1, midRow + 1, rowEnd, targetRow, targetCol, val);
    }
  }
  updateY(nodeX, rowStart, rowEnd, 1, 0, m - 1, targetCol, val);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Input matrix size
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  // Build 2D segment tree
  buildX(1, 0, n - 1);

  // Example query: sum from (x1,y1) to (x2,y2)
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      // Query: sum of submatrix
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      // zero-based indexing assumed
      cout << queryX(1, 0, n - 1, x1, x2, y1, y2) << "\n";
    } else if (type == 2) {
      // Update: set matrix[x][y] = val
      int x, y, val;
      cin >> x >> y >> val;
      updateX(1, 0, n - 1, x, y, val);
    }
  }

  return 0;
}
