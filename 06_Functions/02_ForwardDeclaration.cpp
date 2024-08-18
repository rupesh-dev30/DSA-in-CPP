#include <bits/stdc++.h>
using namespace std;

void sayHello(){        //Declaration
  cout<<"Hello :)"<<endl;       //Definition
}

void sayRupesh();     //Decalare before calling if you want to add definition after calling

int main() {
  // code here
  sayHello();
  sayRupesh();     //function must be initialised before the calling
  
  return 0;
}

void sayRupesh(){
  cout<<"Rupesh :)"<<endl;
}

/*
  Declaration: The function's name, return type, and parameters(if any)

  Definition: The body of the function
*/