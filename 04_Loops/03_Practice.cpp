#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int n;
  cout<<"Enter the number: ";
  cin>>n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cout<<"* ";
    }
    cout<<endl;
  }

  return 0;
}