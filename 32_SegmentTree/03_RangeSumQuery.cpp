#include <bits/stdc++.h>
using namespace std;

vector<int> segment;

int query(int index, int low, int high, int l, int r) {
  // OUT OF RANGE
  if (r < low || l > high) {
    return 0;
  }

  // COMPLETE OVERLAP
  if (l <= low && r >= high) {
    return segment[index];
  }

  // PARTIAL OVERLAP
  int mid = (low + high) / 2;
  int left = query(2 * index + 1, low, mid, l, r);
  int right = query(2 * index + 2, mid + 1, high, l, r);

  return left + right;
}

void build(int index, int low, int high, vector<int> &arr) {
  if (low == high) {
    segment[index] = arr[low];
    return;
  }

  int mid = (low + high) / 2;
  build(2 * index + 1, low, mid, arr);
  build(2 * index + 2, mid + 1, high, arr);

  segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
}

int main() {
  // code here
  vector<int> arr = {3, 1, 2, 7, 1};
  int n = arr.size();

  // RESIZE THE SEGMENT TREE TO 4 * n
  segment.resize(4 * n);

  // BUILD THE SEGMENT TREE
  build(0, 0, n - 1, arr);

  // PRINT
  cout << "Segment Tree" << endl;
  for (int i = 0; i < 4 * n; i++) {
    if (segment[i] != 0) {
      cout << "Segment[" << i << "] = " << segment[i] << endl;
    }
  }

  cout << query(0, 0, n - 1, 3, 4) << endl;

  return 0;
}