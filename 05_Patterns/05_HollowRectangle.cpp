#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: ";
  cin>>num;

  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      if(i == 0 || i == num-1) {
        cout<<"* ";
      } else {
        if(j == 0 || j == num - 1){
          cout<<"* ";
        } else {
          cout<<"  ";
        }
      }
    }
    cout<<endl;
  }

  return 0;
}