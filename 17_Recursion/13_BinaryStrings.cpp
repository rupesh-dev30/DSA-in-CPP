#include <bits/stdc++.h>
using namespace std;

/*
    Print all binary string of size N without any consecutive 1s.
*/

void binaryString(int n, int lastplace, string ans) {
  if (n == 0) {
    cout << ans << endl;
    return;
  }
  if (lastplace != 1) {
    binaryString(n - 1, 0, ans + '0');
    binaryString(n - 1, 1, ans + '1');
  } else {
    binaryString(n - 1, 0, ans + '0');
  }
}

void binaryString(int n, string ans) {
  if (n == 0) {
    cout << ans << endl;
    return;
  }
  if (ans[ans.length() - 1] != '1') {
    binaryString(n - 1, ans + '0');
    binaryString(n - 1, ans + '1');
  } else {
    binaryString(n - 1, ans + '0');
  }
}

int main() {
  // code here
  string ans = "";
  binaryString(3, ans);

  return 0;
}