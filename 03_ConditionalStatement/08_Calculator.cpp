#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int a, b;
  char c;
  cout << "Enter the first number : ";
  cin >> a;
  cout << "Enter the operator : ";
  cin >> c;
  cout << "Enter the second number : ";
  cin >> b;

  switch (c) {
  case '+':
    cout << a + b;
    break;
  case '-':
    cout << a - b;
    break;
  case '*':
    cout << a * b;
    break;
  case '/':
    cout << a / b;
    break;

  default:
    cout << "Wrong or Out of context operator🤔 (this calc is only capable for (+,-,*,/)";
    break;
  }

  return 0;
}