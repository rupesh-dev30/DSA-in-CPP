#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  // data_type array_name [row] [colume] = { {}, {}, {} };
  int student[2][3] = {{100, 100, 100}, {75, 80, 85}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << student[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}