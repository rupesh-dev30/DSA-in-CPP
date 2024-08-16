#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  for(int i=0; i<num; i++){
    for(int j=0; j<=i; j++){
      cout<<"* ";
    }
    for(int j=0; j<num-i-1; j++){
      cout<<"  ";
    }

    for(int j=num-i-1; j>0; j--){
      cout<<"  ";
    }

    for(int j=0; j<=i; j++){
      cout<<"* ";
    }
    cout<<endl;
  }

  for(int i=0; i<num; i++){
    for(int j=0; j<num-i; j++){
      cout<<"* ";
    }
    for(int j=0; j<i; j++){
      cout<<"  ";
    }
    for(int j=0; j<i; j++){
      cout<<"  ";
    }
    for(int j=0; j<num-i; j++){
      cout<<"* ";
    }
    cout<<endl;
  }

  return 0;
}