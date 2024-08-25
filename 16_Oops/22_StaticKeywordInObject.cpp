#include <bits/stdc++.h>
using namespace std;

class Example {
public:
  Example() {
    cout << "Example constructor called" << endl;
  }

  ~Example() {
    cout << "Example destructor called" << endl;
  }
};

int main() {
  // code here
  int a = 0;

  // if(a == 0){
  //   Example ex1;      // It delete immediately when it go outside the if.
  // }

  if (a == 0) {
    static Example ex2;  // It delete after the complete execution of the program.
  }

  cout << "Code Ending...\n";

  return 0;
}

/*
    Static Variables:
        Variables declared as static in a function are created & initialised once for the lifetime of the program.  -> in function

        Static variables in a class are created & initialised once. They are shared by all the objects of the class.  -> in class
*/