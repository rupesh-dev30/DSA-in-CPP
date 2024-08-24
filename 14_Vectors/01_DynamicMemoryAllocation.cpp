#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  // int arr[100] = {1, 2, 3, 4, 5};

  int size;
  cin >> size;

  int *arr = new int[size];
  /*
      arr[0] => *(arr+0)
      arr[1] => *(arr+1)
      arr[2] => *(arr+2)
  */

  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }

  cout << endl;

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}