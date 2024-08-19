#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  //ptr++ or ++ptr
  int arr[] = {1, 2, 3, 4, 5};
  int *ptr = arr;
  cout << *ptr << endl; // 1
  cout << *(ptr++) << endl; // 1
  cout << *ptr << endl; // 2
  cout << *(++ptr) << endl; // 3


  //ptr-- or --ptr
  cout << *(--ptr) << endl; // 2
  cout << *ptr << endl; // 2
  cout << *(ptr--) << endl; // 2
  cout << *ptr << endl; // 1

  return 0;
}