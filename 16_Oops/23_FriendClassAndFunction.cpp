#include <bits/stdc++.h>
using namespace std;

/*
    A friend class or a friend function can access private and protected members of the other classes in which it is declared as a friend.
*/

class A {
  string secret = "secret data";

  friend class B;   // this allow class B to access the private or protected member of this class and it also allow to access the data of B class
  friend void revealSecret(A &obj);
}; 

class B {
  public:
    void showSecret(A &obj){
      cout << obj.secret << endl;  // it give error when there is no friend keyword
    }
};

void revealSecret(A &obj){
  cout << obj.secret << endl;  // it give error when there is no friend keyword
}

int main() {
  // code here
  A a1;
  B b1;

  // b1.showSecret(a1);
  revealSecret(a1);  // it is not allow without friend.

  return 0;
}