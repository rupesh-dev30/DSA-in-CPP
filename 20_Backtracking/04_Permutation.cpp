#include <bits/stdc++.h>
using namespace std;

void permutation(string str, string ans) {
  int n = str.size();
  if (n == 0) {
    cout << ans << endl;
    return;
  }
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];

    // "abcdefg" , i = 2 => "ab" + "defgh"
    string nextStr = str.substr(0, i) + str.substr(i + 1, n - i - 1);
    permutation(nextStr, ans + ch);
  }
}

int main() {
  // code here
  string str = "abc";
  string ans = "";

  permutation(str, ans);
  return 0;
}