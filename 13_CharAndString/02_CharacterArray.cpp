#include <bits/stdc++.h>
using namespace std;

// Character arrays: Store string
// Single : Character quote
// Double: String quote

int main() {
  // code here
  char arr[6] = {'a','b','c','d','e','\0'};
  cout << arr[0] << endl;
  cout << arr[1] << endl;
  cout << arr[2] << endl;
  cout << arr[3] << endl;
  cout << arr[4] << endl;
  cout << arr[5] << endl;
  cout << arr << endl;

  // we can change character array by visiting by index but we cannot change string literals
  //"rupesh" -> string literals
  //"a" -> -> string literals

  return 0;
}


// C O D E \0
//  Expicitly Terminated by null character, \0 (end of string)