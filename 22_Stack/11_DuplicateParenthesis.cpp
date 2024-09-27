#include <bits/stdc++.h>
using namespace std;

bool isDuplicate(string str) {
  stack<char> s;
  for(int i=0; i<str.size(); i++) {
    if(str[i] != ')') {
      s.push(str[i]);
    } else {
      if(s.top() == '(') {
        return true;
      } else {
        while(s.top() != '(') {
          s.pop();
        }
        s.pop();
      }
    }
  }
  return false;
}

int main() {
  // code here
  string str1 = "((a+b))";
  string str2 = "((a+b) + (c+d))";

  if(isDuplicate(str2)) {
    cout << "Duplicate found in string: " << str2 << endl;
  } else {
    cout << "No duplicate found in string: " << str2 << endl;
  }
  

  return 0;
}

/*
    Given a balanced expression that can contain opening and closing parenthesis, check if it contains any duplicate parenthesis or not.

    Input: ((x+y))+2

    Output: true

    Explanation: Duplicate () found in subexpression ((x+y))

    Input: (x+y)

    Output: false

    Explanation: No duplicate (0) is found

    Input: ((x+y)+((2)))

    Output: true

    Explanation: Duplicate () found in subexpression ((z))
*/