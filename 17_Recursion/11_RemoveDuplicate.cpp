#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(string str, string ans, int i, int map[26]) {
  if (i == str.length()) {
    cout << ans << endl;
    return;
  }

  char ch = str[i];
  int mapIndex = ch - 'a';
  if (map[mapIndex] == true) { // duplicate
    removeDuplicates(str, ans, i + 1, map);
  } else {
    map[mapIndex] = true;
    removeDuplicates(str, ans + str[i], i + 1, map);
  }
}

void removeDuplicates(string str, string ans, int map[26]) {
  if (str.length() == 0) {
    cout << ans << endl;
    return;
  }

  int n = str.length();
  char ch = str[n - 1];
  int mapIndex = (str[n - 1] - 'a');
  str = str.substr(0, n - 1);

  if (map[mapIndex]) { // duplicate
    removeDuplicates(str, ans, map);
  } else {
    map[mapIndex] = true;
    removeDuplicates(str, ch + ans, map);
  }
}

int main() {
  // code here
  string str = "ruppesshhkummarr";
  string ans = "";
  int map[26] = {false};

  removeDuplicates(str, ans, map);

  return 0;
}