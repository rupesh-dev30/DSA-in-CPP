#include <bits/stdc++.h>
using namespace std;

// O(n)
int power(int x, int n) {
  if (n == 1) {
    return x;
  }

  return x * power(x, n - 1);
}

// O(logn)
int powerOptimised(int x, int n){
  if(n==0){
    return 1;
  }

  int halfPower = powerOptimised(x, n/2);
  int halfPowerSquare = halfPower * halfPower;

  if(n % 2 != 0) {
    return x * halfPowerSquare;
  }

  return halfPowerSquare;
}

int main() {
  // code here
  cout << power(10, 7) << endl;
  cout << powerOptimised(10,7) << endl;

  return 0;
}