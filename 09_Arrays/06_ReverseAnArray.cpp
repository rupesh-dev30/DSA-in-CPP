#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n, int reverseArray[]){
  int j = 0;

  for(int i=n-1; i>=0; i--){
    reverseArray[j++] = arr[i];
  }
}

void reverse(int arr[], int n){
  int j = n - 1;
  for(int i=0; i<n/2; i++){
    swap(arr[i], arr[j--]);
  }
}

int main() {
  // code here
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
  int reverseArray[10];

  reverse(arr, 10, reverseArray);

  for(int i=0; i<10; i++){
    cout << reverseArray[i] << " ";
  }

  cout << endl;

  reverse(arr1, 10);
  for(int i=0; i<10; i++){
    cout << arr1[i] << " ";
  }

  return 0;
}