#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int n, int key){
  for(int i=0; i<n; i++){
    if(arr[i] == key){
      return true;
    }
  }
  return false;
}

int main() {
  // code here
  int arr[] = {2,4,6,8,10,14,16};
  int key = 10;

  if(linearSearch(arr,7,key)){
    cout << "Element is present in array";
  } else {
    cout << "Element is not present in array";
  }

  return 0;
}


/* 
    Time Complexity : O(sizeofarray) or O(n)
    Space Complexity: o(1)
*/