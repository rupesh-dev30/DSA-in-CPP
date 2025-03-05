#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class State {
public:
  int row, col, dir, turns;
};

bool isValid(int row, int col, vector<vector<char>>& grid, int rows, int cols) {
  return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != 'X');
}

string bfs(vector<vector<char>> &grid, int startRow, int startCol, int endRow, int endCol, int rows, int cols) {
  queue<State> q;
  vector<vector<vector<int>>> visited(rows, vector<vector<int>>(cols, vector<int>()));

  // TRY ALL 4 POSSIBLE INITIAL DIRECTIONS
  for (int d = 0; d < 4; d++) {
    q.push({startRow, startCol, d, 0});
    visited[startRow][startCol][d] = 0;
  }

  while (!q.empty()) {
    State curr = q.front();
    q.pop();

    if (curr.row == endRow && curr.col == endCol) {
      return "DRIVE";
    }

    for (int d = 0; d < 4; d++) {
      int newRow = curr.row + directions[d].first;
      int newCol = curr.col + directions[d].second;
      int newTurns = curr.turns + (curr.dir != d ? 1 : 0);

      if (isValid(newRow, newCol, grid, rows, cols) && newTurns <= 2 && visited[newRow][newCol][d] > newTurns) {
        visited[newRow][newCol][d] = newTurns;
        q.push({newRow, newCol, d, newTurns});
      }
    }
  }
  return "DON'T DRIVE!";
}

int main() {
  // code here
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<char>> grid(rows, vector<char>(cols));

  int startRow, startCol, endRow, endCol;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'Q') {
        startRow = i;
        startCol = j;
      }
      if (grid[i][j] == 'W') {
        endRow = i;
        endCol = j;
      }
    }
  }

  cout << bfs(grid, startRow, startCol, endRow, endCol, rows, cols) << endl;

  return 0;
}