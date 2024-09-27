#include <bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &s, int temp) {
  if(s.empty()){
    s.push(temp);
    return;
  }

  int top = s.top();
  s.pop();
  pushAtBottom(s, temp);
  s.push(top);
}

void reverse(stack<int> &s) {
  if (s.empty()) {
    return;
  }

  int temp = s.top();
  s.pop();
  reverse(s);
  pushAtBottom(s, temp);
}

void print(stack<int> s) {
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main() {
  // code here
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  print(s);
  reverse(s);
  print(s);



  return 0;
}