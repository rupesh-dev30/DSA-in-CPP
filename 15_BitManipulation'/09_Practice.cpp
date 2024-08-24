#include <bits/stdc++.h>
using namespace std;

// WAF to update the ith bit in a number according to given value (0 or 1)

void updateIthbit(int num, int position, int value) {
  num = num & ~(1 << position); // clear ith bit

  num = num | (value << position);

  cout << num << endl;
}

int main() {
  // code here
  updateIthbit(7,2,0);
  updateIthbit(7,3,1);

  return 0;
}