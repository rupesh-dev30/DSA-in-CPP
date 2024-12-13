#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout << "Enter the number :";
  cin >> num;

  // int i = 0;
  // int cnt = 0;
  // while (i < 32) {
  //   if ((num & 1) == 1) {
  //     cnt++;
  //   }
  //   num = (num >> 1);
  //   i--;
  // }

  int cnt = 0;
  while(num > 0){
    int lastDigit = num & 1;
    cnt += lastDigit;

    num = num >> 1;
  }

  cout << cnt;

  return 0;
}