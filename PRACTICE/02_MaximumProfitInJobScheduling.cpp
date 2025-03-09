#include <bits/stdc++.h>
using namespace std;

int find(vector<vector<int>> &array, int n, int index, int nexJob) {
  int start = index;
  int end = n - 1;
  int result = n + 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (array[mid][0] >= nexJob) {
      result = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return result;
}

int solve(vector<vector<int>> &matrix, int n, int i, vector<int> &dp) {
  if (i >= n)
    return 0;
  if (dp[i] != -1) {
    return dp[i];
  }
  int next = find(matrix, n, i + 1, matrix[i][1]);
  int include = matrix[i][2] + solve(matrix, n, next, dp);
  int exclude = solve(matrix, n, i + 1, dp);
  return dp[i] = max(include, exclude);
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
  int n = startTime.size();
  vector<vector<int>> matrix(n, vector<int>(3, 0));

  for (int i = 0; i < n; i++) {
    matrix[i][0] = startTime[i];
    matrix[i][1] = endTime[i];
    matrix[i][2] = profit[i];
  }

  vector<int> dp(n + 1, -1);
  sort(matrix.begin(), matrix.end());

  return solve(matrix, n, 0, dp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;  // Read 'n' first before declaring vectors

  vector<int> startTime(n);
  vector<int> endTime(n);
  vector<int> profit(n);

  for (int i = 0; i < n; i++) {
    cin >> startTime[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> endTime[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> profit[i];
  }

  cout << jobScheduling(startTime, endTime, profit) << endl;

  return 0;
}


/*
    Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
    Output: 120

    Explanation: The subset chosen is the first and fourth job.
    Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/