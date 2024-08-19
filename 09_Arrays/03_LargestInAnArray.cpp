#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int arr[5] = {5,4,3,9,2};
  int maxi = INT_MIN;
  for(int i=0; i<5; i++){
    maxi = max(maxi, arr[i]);
  }

  cout << "Maximum element : "<<maxi;
  
  return 0;
}