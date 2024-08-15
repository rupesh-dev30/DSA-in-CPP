#include <bits/stdc++.h>
using namespace std;

int main() {
  float salary, tax;
  cout<<"Enter your income (in Lakhs) : ";
  cin>>salary;

  if (salary < 5) {
    tax = 0;
  } else if (salary >= 5 && salary <= 10) {
    tax = 0.20 * salary;
  } else {
    tax = 0.30 * salary;
  }

  cout << "Tax = " << (tax * 100000) << endl;
  
  return 0;
}