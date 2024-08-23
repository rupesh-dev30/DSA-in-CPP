#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  char word[] = "ApplE";
  int n = strlen(word);

  for (int i = 0; i < n; i++) {
    if (word[i] >= 'a' && word[i] <= 'z') {

      int key = word[i] - 'a';
      word[i] = 'A' + key;
    }
  }

  cout << word << endl;

  return 0;
}