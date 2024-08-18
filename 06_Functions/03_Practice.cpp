#include <bits/stdc++.h>
using namespace std;

int product(int a, int b){
  return a * b;
}

int main() {
  // code here
  cout<<"Enter the two numbers: ";
  int a , b;
  cin>>a>>b;
  
  cout<<"The product of "<<a<<" and "<<b<<" is "<<product(a,b)<<endl;
  
  return 0;
}