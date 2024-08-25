#include <bits/stdc++.h>
using namespace std;

class Student {
private:
  string name;
  float cgpa;

public:
  // Getter
  void getName() {
    cout << name << endl;
  }
  void getCgpa() {
    cout << cgpa << endl;
  }

  // Setter
  void setName(string name) {
    this->name = name;
  }
  void setCgpa(float cgpa) {
    this->cgpa = cgpa;
  }
};

int main() {
  // code here
  Student s1;
  s1.setName("Rupesh");
  s1.setCgpa(9.6);
  s1.getName();
  s1.getCgpa();

  return 0;
}