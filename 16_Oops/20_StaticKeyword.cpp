#include <bits/stdc++.h>
using namespace std;

void staticCount() {
  static int staticCount = 0;
  staticCount++;
  cout << "Static Count : " << staticCount << endl;
}

void counter() {
  int count = 0;
  count++;
  cout << "Count : " << count << endl;
}

int main() {
  // code here
  counter();
  counter();
  counter();

  staticCount();
  staticCount();
  staticCount();

  return 0;
}

/*
    Static Variables:
        Variables declared as static in a function are created & initialised once for the lifetime of the program.  -> in function

        Static variables in a class are created & initialised once. They are shared by all the objects of the class.  -> in class
*/