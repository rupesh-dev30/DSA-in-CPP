#include <bits/stdc++.h>
using namespace std;

void binaryToDecimal(int binaryNumber) {
  int n = binaryNumber;
  int decimalNumber = 0;

  int i = 0;
  while (n > 0) {
    int temp = n % 10;
    decimalNumber += temp * pow(2, i++);
    n /= 10;
  }

  cout<<decimalNumber;
}

int main() {
  // code here
  int n;
  cout << "Enter the binary number: ";
  cin >> n;

  binaryToDecimal(n);

  return 0;
}