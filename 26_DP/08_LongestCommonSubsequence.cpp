#include <bits/stdc++.h>
using namespace std;

/*
Subsequence is created from a string with characters in the same relative order.

str1 = "abcdge"
str2 = "abedg"

lcd = "abdg"

*/
int lcs(string str1, string str2, int n, int m) {
  if ((n == 0 && m != 0) || (m == 0 && n != 0) || (n == 0 && m == 0)) {
    return 0;
  }
  if (str1[n - 1] == str2[m - 1]) {
    return 1 + lcs(str1, str2, n - 1, m - 1);
  }
  return max(lcs(str1, str2, n - 1, m), lcs(str1, str2, n, m - 1));
}

int lcsAternative(string str1, string str2) {
  int n = str1.length();
  int m = str2.length();

  if ((n == 0 && m != 0) || (m == 0 && n != 0) || (n == 0 && m == 0)) {
    return 0;
  }

  if (str1[n - 1] == str2[m - 1]) {
    return 1 + lcsAternative(str1.substr(0, n - 1), str2.substr(0, m - 1));
  } else {
    return max(lcsAternative(str1.substr(0, n - 1), str2), lcsAternative(str1, str2.substr(0, m - 1)));
  }
}

int main() {
  // code here
  string str1 = "abcdge";
  string str2 = "abedge";
  int n = str1.length();
  int m = str2.length();

  cout << lcs(str1, str2, n, m) << endl;
  cout << lcsAternative(str1, str2) << endl;

  return 0;
}