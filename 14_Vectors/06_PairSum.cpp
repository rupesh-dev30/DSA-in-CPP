#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> arr, int target){
  int start = 0, end = arr.size() - 1;
  int currSum = 0;

  while(start < end) {
    currSum = arr[start] + arr[end];
    if(currSum == target) {
      return {arr[start], arr[end]}; // Return the pair
    } else if (currSum < target) {
      start++;
    } else {
      end --;
    }
  }
  return {-1,-1};
}

int main() {
  // code here
  vector<int> arr = {2, 7, 11, 15};
  int target = 9;

  vector<int> answer = pairSum(arr, target);

  for(int i=0; i<answer.size(); i++){
    cout << answer[i] << " ";
  }

  return 0;
}