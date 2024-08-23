#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  char work[] = "code";
  cout << work << endl;

  char work1[5] = "work"; // 1 extra for null character
  cout << work1 << endl;

  char work2[10] = "work2"; // it add \0 by default and end it
  cout << work2 << endl;

  // char work3[50] = {'c', 'o', 'd', 'e'};
  char work3[50] = {'c', 'o', 'd', 'e', '\0'};
  cout << work3 << endl;
  cout << strlen(work3) << endl;

  return 0;
}