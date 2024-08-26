#include <bits/stdc++.h>
using namespace std;

/*
    Find total ways in which n friends can be paired up.
    Each friend can only be paired once.
*/

int pairFriend(int n) {
  if (n == 1 || n == 2) {
    return n;
  }

  // single
  int ans1 = pairFriend(n - 1);

  // pair
  int ans2 = (n - 1) * pairFriend(n - 2);

  return ans1 + ans2;
}

int main() {
  // code here
  cout << pairFriend(4) << endl;

  return 0;
}