#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  unordered_set<int> s;

  s.insert(1);
  s.insert(1);
  s.insert(1);
  s.insert(1);
  s.insert(3);
  s.insert(5);
  s.insert(2);

  cout << s.size() << endl;

  if(s.find(3) != s.end()) {
    cout << "3 is in the set" << endl;
  } else {
    cout << "3 is not in the set" << endl;
  }

  return 0;
}