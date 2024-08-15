#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int day;
  cout << "Enter the day (in number i.e. Sunday - 0, Monday - 1 ...)";
  cin >> day;

  switch (day) {
  case 0:
    cout << "Sunday";
    break;
  case 1:
    cout << "Monday";
    break;
  case 2:
    cout << "Tuesday";
    break;
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  default:
    cout << "Invalid day";
    break;
  }

  return 0;
}