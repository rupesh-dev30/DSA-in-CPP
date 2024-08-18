#include <bits/stdc++.h>
using namespace std;

int x = 50;  //Global variable and scope

void sum(int a, int b) {
  if (a >= 1) {
    int x = 25; // local variable or scope , it cannot access outside the if statement
    cout << x << endl;
  }

  cout<<x<<endl;  //global variable

  int s = a + b;    //Local
  cout << s << endl;
}

int main() {
  // code here
  sum(5, 4);

  int s = 10;    //Local
  cout << s << endl;

  return 0;
}