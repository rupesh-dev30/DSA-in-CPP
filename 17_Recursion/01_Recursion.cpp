#include <bits/stdc++.h>
using namespace std;

/*
    Recursion: When a function repeatedly calls itself
*/

int cnt = 0;
void func() {
  if(cnt == 5){
    return;
  }
  cout << "Function call...work \n";
  cnt++;
  func();
}

int main() {
  // code here
  func();

  return 0;
}