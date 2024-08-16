#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  int temp = 1;
  for(int i=0; i<num; i++){
    for(int j=0; j<=i; j++){
      cout<<temp<<" ";
      temp++;
    }
    cout<<endl;
  }

  return 0;
}