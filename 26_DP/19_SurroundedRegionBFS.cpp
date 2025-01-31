#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> &board, int i, int j, int m, int n) {
  vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  queue<pair<int,int>> q;
  q.push({i,j});
  board[i][j] = 'T';

  while(!q.empty()) {
    auto [x,y] = q.front();
    q.pop();

    for(auto [dx,dy] : directions) {
      int nx = x + dx;
      int ny = y + dy;

      if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
        board[nx][ny] = 'T';
        q.push({nx,ny});
      }
    }
  }
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
      bfs(board, 0, i, m, n);
    }

    if (board[m - 1][i] == 'O') {
      bfs(board, m - 1, i, m, n);
    }
  }

  // First Col and Last Col
  for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O') {
      bfs(board, i, 0, m, n);
    }
    if (board[i][n - 1] == 'O') {
      bfs(board, i, n - 1, m, n);
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
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
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