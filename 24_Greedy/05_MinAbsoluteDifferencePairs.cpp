#include <bits/stdc++.h>
using namespace std;

int minAbsDiffPairs(vector<int> A, vector<int> B){
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());

  int absDiff = 0;
  for(int i=0; i<A.size(); i++){
    absDiff += abs(A[i]-B[i]);
  }
  return absDiff;
}

int main() {
  // code here
  vector<int> A = {4,1,8,7};
  vector<int> B = {2,3,6,5};

  cout << minAbsDiffPairs(A,B);

  return 0;
}

/*
    Min Absolute Difference Pairs

    Pair elements of A and B to minimize sum of absolute differences between pairs
*/