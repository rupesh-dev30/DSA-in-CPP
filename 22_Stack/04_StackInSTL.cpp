#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);

  while(!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}