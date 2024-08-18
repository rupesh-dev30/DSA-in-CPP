#include <bits/stdc++.h>
using namespace std;

//Print all primes in a range from 2 to n
bool isPrime(int num){
  if(num == 1) return false;

  for(int i = 2; i<=sqrt(num); i++){
    if(num % i == 0) return false;
  }
  return true;
}

void allPrimes(int n){
  for(int i = 2; i<=n; i++){
    if(isPrime(i)){
      cout << i << " ";
    } else {
      continue;
    }
  }
}

int main() {
  // code here
  int n;
  cout<<"Enter the number: ";
  cin>>n;

  allPrimes(n);

  return 0;
}