#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout << "Enter the number: " << endl;
  cin >> num;

  if ((num & 1) == 0) {
    cout << "Even Number!";
  } else {
    cout << "Odd Number!";
  }

  return 0;
}

/*
    Odd: rightmost bit = 1
    Even: rightmost bit = 0

    Bitmask are used to access specific bits in a byte of data
*/