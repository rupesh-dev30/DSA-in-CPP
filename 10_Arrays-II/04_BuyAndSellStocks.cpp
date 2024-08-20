#include <bits/stdc++.h>
using namespace std;

// Buy and Sell Stocks
int maxProfit(int arr[], int n, int profit[]) {
  int bestBuy[100000];

  bestBuy[0] = INT_MAX;
  for(int i=1; i<n; i++){
    bestBuy[i] = min(bestBuy[i-1], arr[i-1]);
  }

  int maxProfit = 0;
  for(int i=0; i<n; i++){
    profit[i] = arr[i] - bestBuy[i];
    maxProfit = max(maxProfit, profit[i]);
  }

  return maxProfit;
}

int main() {
  // code here
  int prices[] = {7, 1, 5, 3, 6, 4};
  int size = 6;
  int profit[6];

  cout << "Maximum profit: " << maxProfit(prices, size, profit);

  return 0;
}


// Time complexity: O(n)
// Space complexity: O(n)

// The time complexity of the maxProfit function is O(n) because we iterate through the array of prices once to calculate the best buy price and then again to calculate the profit for each day. 

// The space complexity is O(n) as well because we are using an additional array of size n (bestBuy) to store the best buy price for each day.