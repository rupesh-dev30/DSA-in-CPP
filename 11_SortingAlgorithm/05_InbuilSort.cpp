#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int arr[] = {5, 2, 9, 4, 3, 1};

  sort(arr, arr + 6);

  // increasing order
  for (int i = 0; i < 6; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  // decreasing order
  sort(arr, arr + 6, greater<int>());
  for (int i = 0; i < 6; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}