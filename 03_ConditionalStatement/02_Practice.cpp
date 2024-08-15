#include <bits/stdc++.h>
using namespace std;


int main() {
    // Print largest of 2 number

    int a, b;
    cout<<"Enter the 2 number : ";
    cin>>a>>b;
    if (a>b) {
      cout<<a<<" is greater!"<<endl;
    } else {
      cout<<b<<" is greater!"<<endl;
    }


    //Odd Even
    int num;
    cout<<"Enter the number to check even or odd: ";
    cin>>num;

    if(num%2 == 0) {
      cout<<"Even";
    } else {
      cout<<"Odd";
    }

    return 0;
}