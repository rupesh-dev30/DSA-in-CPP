#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cout<<"Enter the three numbers: ";
  cin>>a>>b>>c;

  if (a > b && a > c) {
    cout << a << " is greater among all";
  } else if (b > a && b > c) {
    cout << b << " is greater among all";
  } else {
    cout << c << " is greater among all";
  }
  
  return 0;
}