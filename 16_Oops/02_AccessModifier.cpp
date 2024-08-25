#include <bits/stdc++.h>
using namespace std;

class Student {
public:
  string name;
  float cgpa;

  void getPercentage() {
    cout << (cgpa * 10) << "% " << endl;
  }
};

int main() {
  // code here
  Student s1;

  s1.name = "Rupesh";
  cout << s1.name << endl;

  return 0;
}

/*
    Access Modifiers:

        1. private: data & methods accessible inside class
        2. public: data & methods accessible inside class & outside class
        3. protected: data & methods accessible inside class & inside child class
*/