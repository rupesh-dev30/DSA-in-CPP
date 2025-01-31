#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, int i, int j, int m, int n) {
  if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
    return;

  board[i][j] = 'T';

  dfs(board, i - 1, j, m, n);
  dfs(board, i + 1, j, m, n);
  dfs(board, i, j - 1, m, n);
  dfs(board, i, j + 1, m, n);
}

void solve(vector<vector<char>> &board) {
  int m = board.size();
  if (m == 0)
    return;
  int n = board[0].size();

  // Checking Boundary
  // First Row and Last Row
  for (int i = 0; i < n; i++) {
    if (board[0][i] == 'O') {
      dfs(board, 0, i, m, n);
    }

    if (board[m - 1][i] == 'O') {
      dfs(board, m - 1, i, m, n);
    }
  }

  // First Col and Last Col
  for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O') {
      dfs(board, i, 0, m, n);
    }
    if (board[i][n - 1] == 'O') {
      dfs(board, i, n - 1, m, n);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
      if (board[i][j] == 'T') {
        board[i][j] = 'O';
      }
    }
  }
}

int main() {
  // code here
  int m, n;
  cin >> m >> n;

  vector<vector<char>> board(m, vector<char>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  solve(board);

  // Printing
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
    You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.

    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

    To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/