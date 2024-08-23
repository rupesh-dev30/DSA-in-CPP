#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  string str = "rupesh kumar";

  for (int i = 0; i < str.length(); i++) { // string is class , length is defined inside the class , we can access using dot operator. str(.)length();
    cout << str[i] << '-';
  }

  cout << endl;

  for (char ch : str) {
    cout << ch << '-';
  }

  return 0;
}