#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    // code here
    float side;
    cout<<"Enter the size of the square: "<<endl;
    cin>>side;

    float area = side * side;

    cout<<setprecision(10) <<"Area of the square is : "<<area;

    return 0;
}