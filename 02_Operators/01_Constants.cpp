#include <bits/stdc++.h>
#define X = 25
#define ll long long
using namespace std;

int main() {
    // code here
    string name = "Rupesh";
    cout << name << endl;

    name = "Ritesh";
    cout<<name<<endl;

    const string name1 = "Rupesh";
    cout << name1 << endl;

    ll y = 20;
    cout<<sizeof(y)<<endl;

    return 0;
}


/*

  Constant are the variables that cannot be changed

  #Constant must be initialised;

  (This is not allowed)
  const int n;
  n = 25;


  difference between Macros and Constants:

    Macros: Symbolic Constants, it does not take any space in memory. In above code we define X = 25, whenever we cout or use the X in the code, before the runtime , it change to 25 ..

    while constants take the momory space ...

*/
