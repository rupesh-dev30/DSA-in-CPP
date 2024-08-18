#include <bits/stdc++.h>
using namespace std;

int factorial(int num){
  int fact = 1;
  for(int i=2; i<=num; i++){
    fact *= i;
  }

  return fact;
}

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  cout<<"Factorial of "<<num<<" is "<<factorial(num);

  return 0;
}