#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &original) {
  int n = original.size();
  queue<int> first;

  for(int i=0; i<n/2; i++){
    first.push(original.front());
    original.pop();
  }

  while(!first.empty()){
    original.push(first.front());
    first.pop();

    original.push(original.front());
    original.pop();
  }
}

int main() {
  // code here
  queue<int> orginal;
  for (int i = 1; i <= 10; i++) {
    orginal.push(i);
  }

  interleave(orginal);

  for (int i = 1; i <= 10; i++) {
    cout << orginal.front() << " ";
    orginal.pop();
  }
  cout << endl;

  return 0;
}