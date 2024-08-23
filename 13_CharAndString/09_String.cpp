#include <iostream>
#include <string>
using namespace std;

int main() {
  // code here
  string str = "Hello";
  // string -> class and str -> object


  //Taking whitespace 
  string str2;
  getline(cin, str2);

  cout << str << endl;
  str = "Rupesh";
  cout << str << endl;

  cout << str2 << endl;

  return 0;
}

/*
    C++ strings are objects of pre defined string class in STL (Standard Template Library)

    C++ strings have useful member functions.

    C++ strings are dynamic (their size can change at run time).

    C++ strings support operators like +, == , >, < etc.

    C++ strings are stored contiguosly in memory
*/