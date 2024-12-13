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

  cout << (num | bitMask) << endl;

  return 0;
}