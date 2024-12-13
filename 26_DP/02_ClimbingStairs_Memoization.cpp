#include <bits/stdc++.h>
using namespace std;

int countWay(int n, vector<int> &dp){
  if(n==0 || n==1) return 1;

  if(dp[n] != -1) {
    return dp[n];
  }

  return dp[n] = countWay(n-1, dp) + countWay(n-2, dp);
}

int main() {
  // code here
  int n = 4;
  vector<int> dp(n+1, -1);

  cout << countWay(n, dp);

  return 0;
}