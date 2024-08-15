#include <bits/stdc++.h>
using namespace std;

int main() {
  int marks;
  cout<<"Enter the marks (not more than 100) :";
  cin>>marks;

  if (marks >= 90) {
    cout<<"A"<<endl;
  } else if (marks >= 80 && marks < 90) {
    cout <<"B"<<endl;
  } else {
    cout<<"Rankers"<<endl;
  }
  
  return 0;
}