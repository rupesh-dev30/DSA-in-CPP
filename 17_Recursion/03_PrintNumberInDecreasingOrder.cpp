#include <bits/stdc++.h>
using namespace std;

void printNumber(int n) {
  if (n == 0) {
    return;
  }

  // cout << n << endl;   // Decreasing Order
  printNumber(n - 1);
  cout << n << endl;   // Increasing Order
}

int main() {
  // code here
  int n;
  cout << "Enter the number: ";
  cin >> n;

  printNumber(n);

  return 0;
}