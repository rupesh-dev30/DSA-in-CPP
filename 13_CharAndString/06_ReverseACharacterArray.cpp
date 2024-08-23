#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  char ch[] = "Apple";
  int i = 0, j = strlen(ch) - 1;

  while(i < j){
    swap(ch[i++], ch[j--]);
  }

  cout << ch;

  return 0;
}