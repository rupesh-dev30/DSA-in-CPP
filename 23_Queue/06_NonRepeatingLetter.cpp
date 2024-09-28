#include <bits/stdc++.h>
using namespace std;

void firstNonRepeating(string str) {
  queue<char> Q;
  int freq[26] = {0};

  for(int i=0; i<str.length(); i++) {
    Q.push(str[i]);
    freq[str[i] - 'a']++;

    while(!Q.empty() && freq[Q.front() - 'a'] > 1) {
      Q.pop();
    }

    if(Q.empty()) {
      cout << "-1" << endl;
    } else {
      cout << Q.front() << endl;
    }
  }
};

int main() {
  // code here
  string str = "aabccxb";

  firstNonRepeating(str);

  return 0;
}

/*
  Find 1st non-repeating letter in a stream of characters


  example :  str = a a b c c x b

  a                  a
  a a                -1
  a a b              b
  a a b c            b
  a a b c c          b
  a a b c c x        b
  a a b c c x b      x

*/