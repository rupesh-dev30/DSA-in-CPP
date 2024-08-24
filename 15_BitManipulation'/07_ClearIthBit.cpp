#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  // code here
  int num;
  cout << "Enter the number: ";
  cin >> num;
  int position;
  cout << "Enter the position: ";
  cin >> position;

  int bitMask = ~(1 << position);   // 1 1 1 1 1 0 1 1 1 1 -> we need somthing like this

  cout << (num & bitMask) << endl;

  return 0;
}