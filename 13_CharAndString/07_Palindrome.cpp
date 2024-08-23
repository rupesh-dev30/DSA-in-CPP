#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(char ch[], int n){
  int i = 0, j = n - 1;
  while(i < j){
    if(ch[i] == ch[j]){
      i++, j--;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  // code here
  char ch[] = "RUPUR";
  int n = strlen(ch);
  if(isPalindrom(ch, n)){
    cout << "Yes, it is a palindrome.";
  } else {
    cout << "No, it is not a palindrome.";
  };

  return 0;
}