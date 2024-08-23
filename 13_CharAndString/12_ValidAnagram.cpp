#include <bits/stdc++.h>
using namespace std;

//string is not a pointer, so we dont need take a size. because it is not storing the address

bool anagram(string str1, string str2){
  if(str1.length() != str2.length()) return false;

  int count[26] = {0};
  for(int i=0; i<str1.length(); i++){
    int index = str1[i] - 'a';
    count[index]++;
  }

  for(int i=0; i<str2.length(); i++){
    int index = str2[i] - 'a';
    if(count[index] == 0) return false;
    else count[index]--;
  }

  return true;
}

int main() {
  // code here
  string str1 = "rupesh";
  string str2 = "puresh";

  if(anagram(str1,str2)){
    cout<<"Anagram"<<endl;
  } else {
    cout<<"Not Anagram"<<endl;
  }

  return 0;
}