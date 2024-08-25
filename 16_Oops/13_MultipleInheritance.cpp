#include <bits/stdc++.h>
using namespace std;

class Teacher {
public:
  int salary;
  string subjects;
};

class Student {
public:
  int rollno;
  float cgpa;
};

class TA : public Teacher, public Student {
public:
  string name;
};

int main() {
  // code here
  TA t;
  t.name = "Rupesh";
  t.subjects = "nextjs";
  t.salary = 50000;
  t.rollno = 1;
  t.cgpa = 9.5;
  cout << "Name: " << t.name << endl;

  return 0;
}