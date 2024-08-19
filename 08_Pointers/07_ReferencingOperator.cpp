#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int a = 10;
  int &b = a;

  b = 25;

  cout << a << endl;
  cout << b << endl;

  a = 30;
  cout << a << endl;
  cout << b << endl;

  return 0;
}