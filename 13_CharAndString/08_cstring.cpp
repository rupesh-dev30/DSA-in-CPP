#include <cstring>
#include <iostream>
using namespace std;

int main() {
  // code here
  char str1[20];
  char str2[20] = "developer ";
  char str3[10] = "rupesh";
  char str4[10] = "rupesh";
  // str1 = "rupesh kumar";
  strcpy(str1, "rupesh kumar");
  cout << str1 << endl;

  strcpy(str1, str2);
  cout << str1 << endl;

  strcat(str2, str1);
  cout << str2 << endl;

  cout << strcmp(str3, str4);  // 0 -> Equal and 1 -> Not Equal
  // Note: in cmp: first character is smaller than the other string first charactre then positive value and vice verse

  return 0;
}

/*
    cstring functions:
    1. c_str() : returns a pointer to the string

    2. strlen() : returns the length of the string

    3. strcpy(str1, str2) : copies the string from source to destination

    4. strncpy() : copies the string from source to destination, but it stops when it reaches the specified number of characters

    5. strcat(str1, str2) : concatenates the string from source to destination

    6. strncat() : concatenates the string from source to destination, but it stops when it reaches the specified number of characters

    7. strcmp(str1, str2) : compares 2 string based on value,
*/