#include <bits/stdc++.h>
using namespace std;

int main() {
    // code here
    float principal, rate, time;
    cout<<"Enter the Principal : ";
    cin>>principal;
    cout<<"Enter the Rate : ";
    cin>>rate;
    cout<<"Enter the Time : ";
    cin>>time;

    float output = (principal * rate * time) / 100;

    cout<<"Simple intrest is : "<<output;

    return 0;
}