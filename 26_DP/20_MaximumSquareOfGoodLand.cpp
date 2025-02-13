#include <bits/stdc++.h>
using namespace std;

/*
    A farmer wants to cultivate their land in the largest possible square area where good land is present. The land is represented as a matrix of 1s and 0s, where 1 indicates good land and 0 represents bad land. The farmer can only farm within a square of good land with the maximum possible area. Your task is to help the farmer determine the maximum area of the square they can farm in good land.
    
    INPUT:
          0  1  1  0  1
          1  1  0  1  0
          0  1  1  1  0
          1  1  1  1  0
          1  1  1  1  1
          0  0  0  0  0

    OUTPUT: 9

*/

int maxSquareArea(vector<vector<int>> &land) {
  if(land.empty()) return 0;

  int rows = land.size();
  int cols = land[0].size();

  vector<vector<int>> dp(rows, vector<int> (cols, 0));
  int maxSide = 0;

  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      if(land[i][j] == 1) {
        if(i == 0 || j == 0) {
          dp[i][j] = 1; // first row/ column can only be 1 itself
        } else {
          dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
        maxSide = max(maxSide, dp[i][j]);
      }
    }
  }

  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }


  return maxSide * maxSide;
}

int main() {
  // code here
  int m, n;
  cin >> m >> n;

  vector<vector<int>> land(m, vector<int> (n));
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      cin >> land[i][j];
    }
  }

  cout << endl << endl;

  cout << maxSquareArea(land);

  return 0;
}