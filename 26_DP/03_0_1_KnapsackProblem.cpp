#include <bits/stdc++.h>
using namespace std;

// Recurssion
int knapsack(int val[], int wt[], int n, int w) {
  if (w == 0 || n == 0) {
    return 0;
  }

  if (wt[n - 1] <= w) {
    int include = val[n - 1] + knapsack(val, wt, n - 1, w - wt[n - 1]);
    int exclude = knapsack(val, wt, n - 1, w);
    return max(include, exclude);
  } else {
    return knapsack(val, wt, n - 1, w);
  }
}

int main() {
  // code here
  int val[] = {15, 14, 10, 45, 30};
  int wt[] = {2, 5, 1, 3, 4};
  int w = 7;
  int n = 5;

  cout << knapsack(val, wt, n, w) << endl;

  return 0;
}