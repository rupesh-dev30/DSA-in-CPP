#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int num;
  cout<<"Enter the number: "<<endl;
  cin>>num;

  if (num <= 1) {
    cout << "The number is not prime" << endl;
    return 0;
  }

  int count = 0;
  for(int i=2; i<= sqrt(num); i++){
    if(num%i==0){
      count++;
      break;
    }
  }

  if(!count) {
    cout << "The number is prime" << endl;
  } else {
    cout << "The number is not prime" << endl;
  }

  return 0;
}