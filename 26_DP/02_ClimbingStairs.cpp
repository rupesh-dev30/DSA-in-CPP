#include <bits/stdc++.h>
using namespace std;

// Count ways to reach the nth stair. A person can climb 1 or 2 staits at a time.
int countWaysRec(int n){
  if(n==0 || n==1){
    return 1;
  }

  return countWaysRec(n-1) + countWaysRec(n-2);
}

int main() {
  // code here
  int n = 4;
  cout << countWaysRec(n) << endl;

  return 0;
}