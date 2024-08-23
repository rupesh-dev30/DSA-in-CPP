#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  // char word[10];
  // cin >> word; // it ignore the whitespace , for whitespace we use getline

  // cout << "Your word was : " << word << endl;
  // cout << "length : " << strlen(word);

  char text[50];
  // cin.getline(text, 50);
  cin.getline(text, 50, '*');

  cout << "Your word was : " << text << endl;
  cout << "length : " << strlen(text);

  return 0;
}