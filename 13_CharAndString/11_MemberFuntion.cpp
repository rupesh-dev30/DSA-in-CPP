#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  string str = "rupesh kumar kumar";

  cout << str.length() << endl;
  cout << str[4] << endl;
  cout << str.at(4) << endl;
  cout << str.substr(1, 4) << endl;
  cout << str.find("kumar") << endl;
  cout << str.find("kumar", 8) << endl;  // after 7th index , next occurence
  cout << str.find("ritesh") << endl;  // not present. it return large value 

  return 0;
}