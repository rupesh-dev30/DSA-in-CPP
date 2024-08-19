#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int a = 100;
  int *p1 = &a;
  int **p2 = &p1;
  int ***p3 = &p2;

  cout << p2 << endl;
  cout << *p2 << endl;
  cout << **p2 << endl;
  cout << p1 << endl;
  cout << *p1 << endl;
  cout << *p3 << endl;
  cout << **p3 << endl;
  cout << ***p3 << endl;

  return 0;
}