#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
  if (n <= 0) {
    return false;
  }

  int count = 0;

  while (n > 0) {
    if (n & 1) {
      count++;
    }

    n >>= 1;
  }

  return count == 1;
}

int main() {
  // code here
  int num;
  cout << "Enter the number: ";
  cin >> num;

  if (!(num & (num - 1))) {
    cout << "The number is a power of 2";
  } else {
    cout << "The number is not a power of 2";
  }

  cout << endl;
  
  if(isPowerOfTwo(num)){
    cout << "The number is a power of 2";
  } else {
    cout << "The number is not a power of 2";
  }

  return 0;
}