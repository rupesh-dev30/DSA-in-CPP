#include <bits/stdc++.h>
using namespace std;

/*
  Input: arr[] = {1, 2, 3}
  Output: {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 2, 1}, {3, 1, 2}
*/
void solvePermutation(vector<vector<int>> &result, vector<int> arr, int index) {
  if (index == arr.size()) {
    result.push_back(arr);
    return;
  }

  for (int i = index; i < arr.size(); i++) {
    swap(arr[index], arr[i]);

    solvePermutation(result, arr, index + 1);

    // backtracking
    swap(arr[index], arr[i]);
  }
}

vector<vector<int>> permutation(vector<int> &arr) {
  vector<vector<int>> result;

  solvePermutation(result, arr, 0);

  return result;
}

int main() {
  // code here
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> res = permutation(arr);

  for (auto v : res) {
    for (int n : v) {
      cout << n << " ";
    }
    cout << endl;
  }

  return 0;
}