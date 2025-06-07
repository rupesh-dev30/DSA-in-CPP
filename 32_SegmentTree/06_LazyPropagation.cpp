/*
    Problem:
      Aapko ek array diya gaya hai, aur aapko karna hai:

        Multiple range updates: ek range [l, r] mein sab values mein +x add karo.

        Multiple range queries: kisi range ka sum chahiye.

    Agar aap har baar update ke liye pura range traverse karoge → O(n) per update
    Toh queries zyada hone pe code slow ho jaayega.


    Lazy Propagation:

      Hum "lazy" updates ko future ke liye store kar lete hain, aur tabhi apply karte hain jab zarurat padti hai.


    Core Idea:
      Ek lazy[] array banate hain, same size as segment[]

      Agar kisi node par update karna hai, lekin uske children ko update nahi karna abhi → lazy[index] mein store kar lo

      Jab future mein query ya update aata hai us range pe, tab apply karo

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> segment, lazy;

// BUILD SEGEMENT TREE
void build(int index, int low, int high, vector<int> &arr) { // O(n)
  if (low == high) {
    segment[index] = arr[low];
    return;
  }

  int mid = (low + high) / 2;
  build(2 * index + 1, low, mid, arr);
  build(2 * index + 2, mid + 1, high, arr);

  segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
}

// RANGE UPDATE QUERY
void rangeUpdate(int index, int low, int high, int l, int r, int val) { // O(logn)
  if (lazy[index] != 0) {
    segment[index] += (high - low + 1) * lazy[index];

    if (low != high) {
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }

    lazy[index] = 0;
  }

  // NO OVERLAP
  if (r < low || l > high) {
    return;
  }

  // COMPLETE OVERLAP
  if (l <= low && high <= r) {
    segment[index] += (high - low + 1) * val;
    if (low != high) {
      lazy[2 * index + 1] += val;
      lazy[2 * index + 2] += val;
    }
    return;
  }

  // PARTIAL OVERLAP
  int mid = (low + high) / 2;
  rangeUpdate(2 * index + 1, low, mid, l, r, val);
  rangeUpdate(2 * index + 2, mid + 1, high, l, r, val);
  segment[index] = segment[2 * index + 1] + segment[2 * index + 2];
}

int rangeQuery(int index, int low, int high, int l, int r) { // O(logn)
  // APPLY PENDING UPDATE
  if (lazy[index] != 0) {
    segment[index] += (high - low + 1) * lazy[index];
    if (low != high) {
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    lazy[index] = 0;
  }

  // NO OVERLAP
  if (r < low || high < l)
    return 0;

  // COMPLETE OVERLAP
  if (l <= low && high <= r)
    return segment[index];

  // PARTIAL OVERLAP
  int mid = (low + high) / 2;
  int left = rangeQuery(2 * index + 1, low, mid, l, r);
  int right = rangeQuery(2 * index + 2, mid + 1, high, l, r);
  return left + right;
}

int main() {
  // code here

  return 0;
}