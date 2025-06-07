#include <bits/stdc++.h>
using namespace std;

vector<int> segment;

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

void update(int index, int low, int high, int i, int val) {
  if (low == high) {
    segment[index] = val;
    return;
  }

  int mid = (low + high) / 2;

  if (i <= mid) {
    update(2 * index + 1, low, mid, i, val);
  } else {
    update(2 * index + 2, mid + 1, high, i, val);
  }

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

  update(0,0,n-1,1,12);

  cout << "Segment Tree" << endl;
  for (int i = 0; i < 4 * n; i++) {
    if (segment[i] != 0) {
      cout << "Segment[" << i << "] = " << segment[i] << endl;
    }
  }

  return 0;
}