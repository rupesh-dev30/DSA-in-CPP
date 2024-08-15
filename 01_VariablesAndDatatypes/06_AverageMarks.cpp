#include <bits/stdc++.h>
using namespace std;

int main() {
    // code here
    int english;
    int science;
    int maths;

    cout<<"Enter the marks in respective orders: English, Science, Maths" << endl;
    cin>>english>>science>>maths;

    int average = (english + science + maths) / 3;
    cout << "Average of these 3 subjects are: " << average;

    return 0;
}