#include <bits/stdc++.h>
using namespace std;

int factorial(int num){
  int fact = 1;
  
  for(int i=2; i<=num; i++){
    fact *= i;
  }

  return fact;
}

int binomialCoefficient(int n, int r){
  int numerator = factorial(n);
  int denominator = factorial(r) * factorial(n-r);

  return numerator / denominator;
}

int main() {
  // code here
  int n, r;
  cout<<"Enter the n: ";
  cin>>n;
  cout<<"Enter the r: ";
  cin>>r;

  int result = binomialCoefficient(n , r);
  cout<<"The binomial coefficient is: "<<result;

  return 0;
}