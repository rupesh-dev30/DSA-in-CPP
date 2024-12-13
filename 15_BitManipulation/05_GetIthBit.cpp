#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout << "Enter the number: ";
  cin >> num;
  int position;
  cout << "Enter the position: ";
  cin >> position;
  int bitMask = (1 << position);

  if(num & bitMask) {
    cout << "Bit at position " << position << " is 1";
  } else {
    cout << "Bit at position " << position << " is 0";
  }

  return 0;
}

/*

                1 0 0 1 1 1 0 1 0 1
                | | | | | | | | | |
      ith bit:  9 8 7 6 5 4 3 2 1 0
*/