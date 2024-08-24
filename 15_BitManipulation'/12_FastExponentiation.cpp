#include <bits/stdc++.h>
using namespace std;

void fastExponentiation(int x, int n) {
  int ans = 1;

  while (n > 0) {
    int lastBit = n & 1;
    if (lastBit) {
      ans = ans * x;
    }
    x *= x;
    n = n >> 1;
  }
  cout << ans;
}

int main() {
  // code here
  fastExponentiation(2, 5);

  return 0;
}