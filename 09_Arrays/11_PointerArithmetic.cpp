#include <bits/stdc++.h>
using namespace std;

// Addition and Subtraction of pointer

int main() {
  // code here
  int a = 5;
  int *p = &a;
  int *q = p + 3;
  cout << q << endl;
  cout << p << endl;

  // cout << p + q << endl;  There is no sense
  cout << q - p << endl;

  return 0;
}