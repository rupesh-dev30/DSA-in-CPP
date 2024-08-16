#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: "<<endl;
  cin>>num;

  for(int i=0; i<num; i++){
    for(int j=0; j<num-i-1; j++){
      cout<<"  ";
    }
    for(int j=0; j<=i; j++){
      cout<<"* ";
    }

    cout<<endl;
  }

  return 0;
}