#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  int n1 = 0, n2 = 1, n3;

  for(int i=3; i<=num; i++){
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
  }
  cout<<n3;

  return 0;
}