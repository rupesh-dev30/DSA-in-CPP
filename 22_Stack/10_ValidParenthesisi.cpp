#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
  stack<char> s;

  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (ch == '(' || ch == '[' || ch == '{') {
      s.push(ch);
    } else {
      if (s.empty()) {
        return false;
      }

      char top = s.top();
      if (
        (ch == ')' && top == '(') || 
        (ch == '}' && top == '{') || 
        (ch == ']' && top == '[')
      ) {
        s.pop();
      } else {
        return false;
      }
    }
  }
  
  return s.empty();
}

int main() {
  // code here
  string str1 = "([}])";
  string str2 = "([{}])";\

  if(isValid(str2)){
    cout << "Valid" << endl;
  } else {
    cout << "Not Valid" << endl;
  }

  return 0;
}