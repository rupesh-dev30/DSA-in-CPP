#include <bits/stdc++.h>
using namespace std;

/*
    Create a User class with properties: id(private), username(public) & password(private).

    Its id should be initialized in a parameterised constructor.

    It should have a Getter and Setter for password.
*/

class User {
  private:
    int id;
    string password;

  public:
    string username;

    User(int id, string username) {
      this->id = id;
      this->username = username;
    }

    void setPassword(string password) {
      this->password = password;
    }

    void getPassword() {
      cout << this->password << endl;
    }
};

int main() {
  // code here
  User u1(1, "rupesh30");
  u1.setPassword("123456");

  cout << u1.username << endl;

  return 0;
}