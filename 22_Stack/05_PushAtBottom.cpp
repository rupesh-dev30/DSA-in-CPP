#include <bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &s, int N) {
  if(s.empty()){
    s.push(N);
    return;
  }

  int top = s.top();
  s.pop();
  pushAtBottom(s, N);
  s.push(top);
}

int main() {
  // code here
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  pushAtBottom(s, 4);
  s.push(5);
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }

  

  return 0;
}


/*
    NOTE: 

      All container in STL (i.e., vector, list, stack ...)
        -> PASS BY VALUES


        for change globally we use &
*/