#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  for(int i=0; i<num; i++){
    for(int j=num-i; j>5; j--){
      cout<<"* ";
    }
    cout<<endl;
  }

  return 0;
}