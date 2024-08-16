#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  int fact = 1;
  for(int i=2; i<=num; i++){
    fact = fact * i;
  }

  cout<<"Factorial of "<<num<<" : "<<fact;

  return 0;
}