#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  return fib(n - 1) + fib(n - 2);
}

int main() {
  // code here
  int n;
  cout << "Enter the number: ";
  cin >> n;

  cout << "Fibonacci: " << fib(n);

  return 0;
}