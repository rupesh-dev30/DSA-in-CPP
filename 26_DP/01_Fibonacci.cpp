#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
  if(n==0 || n==1) return n;

  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  // code here
  int n = 6;
  cout << fibonacci(n) << endl;
  return 0;
}


