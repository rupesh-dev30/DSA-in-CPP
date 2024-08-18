#include <bits/stdc++.h>
using namespace std;

void decimalToBinary(int decimalNumber){
  int n = decimalNumber;
  int pow = 1;
  int binaryNumber = 0;

  while(n>0){
    int rem = n % 2;
    binaryNumber += rem * pow;
    n = n / 2;
    pow *= 10;
  }

  cout<<binaryNumber;
}

int main() {
  // code here
  int n;
  cout<<"Enter the decimal number: ";
  cin>>n;

  decimalToBinary(n);

  return 0;
}