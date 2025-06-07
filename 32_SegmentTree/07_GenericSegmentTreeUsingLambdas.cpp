#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
  vector<T> segment;
  int n;
  function<T(T, T)> operation;

  T identity;

public:
  SegmentTree(vector<T> &arr, function<T(T, T)> op, T id) {
    n = arr.size();
    operation = op;
    identity = id;
    segment.resize(4 * n, identity);
    build(0, 0, n - 1, arr);
  }

  void build(int index, int low, int high, vector<T> &arr) {
    if (low == high) {
      segment[index] = arr[low];
      return;
    }

    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid, arr);
    build(2 * index + 2, mid + 1, high, arr);
    segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
  }

  void update(int index, int low, int high, int i, T val) {
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

    segment[index] = operation(segment[2 * index + 1], segment[2 * index + 2]);
  }

  T query(int index, int low, int high, int l, int r) {
    if (r < low || high < l)
      return identity;

    if (l <= low && r >= high)
      return segment[index];

    int mid = (low + high) / 2;
    T left = query(2 * index + 1, low, mid, l, r);
    T right = query(2 * index + 2, mid + 1, high, l, r);

    return operation(left, right);
  }

  // EASY EXTERNAL CALLS
  void update(int i, T val) {
    update(0, 0, n - 1, i, val);
  }

  T query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

int main() {
  vector<int> arr = {3, 1, 2, 7, 1};

  // SUM Segment Tree
  SegmentTree<int> segSum(arr, [](int a, int b) { return a + b; }, 0);

  cout << "Sum [0, 4]: " << segSum.query(0, 4) << endl; // 14
  segSum.update(1, 12);
  arr[1] = 12;                                                        // Also update the array if you want to reuse it
  cout << "After update: Sum [0, 4]: " << segSum.query(0, 4) << endl; // 25

  // MIN Segment Tree (on updated array)
  SegmentTree<int> segMin(arr, [](int a, int b) { return min(a, b); }, INT_MAX);
  cout << "Min [1, 3]: " << segMin.query(1, 3) << endl; // Now should return 2

  return 0;
}
