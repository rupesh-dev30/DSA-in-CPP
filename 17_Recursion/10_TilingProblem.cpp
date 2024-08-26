#include <bits/stdc++.h>
using namespace std;

/*
  Optimised Approach: Dynamic Programming

  Current : Recursion
    Tiling Problem:
      - Count total ways to tile a floor (2xn) with tiles (2x1)
*/

int countWays(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  // Vertical
  int ans1 = countWays(n - 1); // 2 x n-1

  // horizontal
  int ans2 = countWays(n - 2); // 2 x n-2

  return ans1 + ans2;
}

int main() {
  // code here
  int n = 5;
  cout << countWays(n) << endl;

  return 0;
}