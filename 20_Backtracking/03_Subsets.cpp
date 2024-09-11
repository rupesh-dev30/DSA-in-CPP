#include <bits/stdc++.h>
using namespace std;

void printSubsets(string str, string subset) {
  if (str.size() == 0) {
    cout << subset << endl;
    return;
  }

  char ch = str[0];

  // Yes Choice
  printSubsets(str.substr(1, str.size() - 1), subset + ch);

  // No choice
  printSubsets(str.substr(1, str.size() - 1), subset);
}

int main() {
  // code here
  string str = "abcdefghijklmnopqrstuvwxyz";
  string subset = "";

  printSubsets(str, subset);

  return 0;
}

/*
    " a b c"

      - subsets: "a", "b", "c", "ab", "bc", "ac", "abc", ""

*/