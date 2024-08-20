#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int arr[20] = {1, 2, 3, 4, 5, 6};
  int *ptr1 = arr;
  int *ptr2 = ptr1 + 3;

  cout << *ptr1 << endl;
  cout << *ptr2 << endl;
  bool result = *ptr2 > *ptr1;
  cout << result;

  return 0;
}