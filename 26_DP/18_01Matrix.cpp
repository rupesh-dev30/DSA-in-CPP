#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  // used to strore the i, j for location
  queue<pair<int, int>> q;

  // if the mat[i][j] == 0 then change the dist[i][j] to 0 because it is already shorter 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

  // BFS
  while(!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for(auto [dx,dy] : directions) {
      int nx = dx + x;
      int ny = dy + y;

      // check out of bound
      if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if(dist[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx,ny});
        }
      }
    }
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  vector<vector<int>> ans = updateMatrix(mat);

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}