#include <bits/stdc++.h>
using namespace std;

/*
    Classes : group of these entities
    Objects : individual entities
*/

class Student {
  // Properties
  string name;
  float cgpa;

  // Methods
  void getPercentage() {
    cout << (cgpa * 10) << "%" << endl;
  }
};

class User {
  int id;
  string username;
  string password;
  string bio;

  void deactivate(){
    cout << "User Deactivated" << endl;
  }

  void editBio(string newBio) {
    bio = newBio;
    cout << "Bio updated successfully" << endl;

  }
};

int main() {
  // code here
  Student s1;  // Object
  cout << sizeof(s1) << endl;
  

  return 0;
}