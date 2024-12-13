#include <bits/stdc++.h>
using namespace std;

// WAF to clear last i bits of a number
void clearIBits(int num, int i) {
  int bitMask = (~0) << i;
  num = num & bitMask;

  cout << num << endl;
}

int main() {
  // code here
  clearIBits(15, 2);

  return 0;
}