#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  char ch = 'A';
  for(int i=0; i<num; i++){
    for(int j=0; j<=i; j++){
      cout<<ch<<" ";
      ch++;
    }
    cout<<endl;
  }

  return 0;
}