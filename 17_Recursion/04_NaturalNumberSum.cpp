#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  if (n == 1) {
    return 1;
  }

  return n + sum(n - 1);
}

int main() {
  // code here
  int n;
  cout << "Enter the number: ";
  cin >> n;

  cout << "Sum: " << sum(n);

  return 0;
}