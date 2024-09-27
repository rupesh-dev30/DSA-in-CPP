#include <bits/stdc++.h>
using namespace std;

string reverseString(string str) {
  string reversed = "";

  stack<char> s;

  for(int i=0; i<str.length(); i++) {
    s.push(str[i]);
  } 

  while(!s.empty()) {
    reversed += s.top();
    s.pop();
  }

  return reversed;
}

int main() {
  // code here
  string str = "Rupesh Kumar";
  cout << reverseString(str) << endl;

  return 0;
}