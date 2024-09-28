#include <bits/stdc++.h>
using namespace std;

void interleave2Queue(vector<int> arr) {
  int n = arr.size();
  queue<int> q1, q2;

  for(int i=0; i<n/2; i++){
    q1.push(arr[i]);
    q2.push(arr[i+n/2]);
  }

  if(n%2 != 0) q1.push(arr[n/2]);
  
  while(!q1.empty()){
    cout << q1.front() << " ";
    q1.pop();
    cout << q2.front() << " ";
    q2.pop();
  }
}

int main() {
  // code here
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

  interleave2Queue(arr);
  

  return 0;
}

/*
    Interleave 2 halves of a queue of even size


    example: 1 2 3 4 5 | 6 7 8 9 10

    output:  1 6 2 7 3 8 4 9 5 10
*/