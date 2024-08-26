#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
  if (n == 0)
    return 1;

  return n * factorial(n - 1);
}

int main() {
  // code here
  int n;
  cout << "Enter the number: ";
  cin >> n;

  cout << "Factorial of " << n << " is " << factorial(n);

  return 0;
}