#include <bits/stdc++.h>
using namespace std;

int trappingRainwater(int height[], int n) {
  int leftMax[20000];
  int rightMax[20000];

  // leftMax[0] = height[0];
  leftMax[0] = INT_MIN;

  for (int i = 1; i < n; i++) {
    leftMax[i] = max(leftMax[i - 1], height[i - 1]);
  }

  // rightMax[n-1] = height[n-1];
  rightMax[n - 1] = INT_MIN;

  for (int i = n - 2; i >= 0; i--) {
    rightMax[i] = max(rightMax[i + 1], height[i + 1]);
  }

  int trapWater = 0;
  // for(int i=0; i<n-1; i++){
  //   int minH = min(leftMax[i], rightMax[i]);
  //   if (currWater > 0) {
  //     trapWater += currWater;
  //   }
  // }

  for (int i = 1; i < n - 1; i++) {
    int minH = min(leftMax[i], rightMax[i]);
    int currWater = minH - height[i];
    if (currWater > 0) {
      trapWater += currWater;
    }
  }

  return trapWater;
}

int main() {
  // code here
  int height[7] = {4, 2, 0, 6, 3, 2, 5};
  int size = 7;

  cout << "Trapping Rainwater : " << trappingRainwater(height, size) << endl;

  return 0;
}