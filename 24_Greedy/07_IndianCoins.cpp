#include <bits/stdc++.h>
using namespace std;

int getMinChange(vector<int> coins, int V) {
  int ans = 0;
  int n = coins.size();

  for (int i = n - 1; i >= 0 && V > 0; i--) {
    if (V >= coins[i]) {
      ans += V / coins[i];
      V = V % coins[i];
    }
  }
  return ans;
}

int main() {
  // code here
  vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
  int V = 1099;

  cout << getMinChange(coins, V);

  return 0;
}

/*
    We are given an infinite supply of denominations [1,2,5,10,20,50,100,500,2000]

    Find the minimum number of coins to make change for a value V

    V = 121
    ans = 3 (100+20+1)

    V = 590
    ans = 4(500+50+20+20)
*/