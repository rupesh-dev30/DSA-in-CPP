#include <bits/stdc++.h>
using namespace std;

/*
    Find number of ways to reach from (0,0) to (N-1, M-1) in a NxM Grid

    Allowed Moves: Right or Down
*/

int gridWays(int r, int c, int n, int m) {
  if(r == n-1 && c == m-1) {   //Destination
    return 1;
  }

  if(r >= n || c >= m) {
    return 0;
  }

  //right
  int val1 = gridWays(r, c+1, n, m);

  //down
  int val2 = gridWays(r+1, c, n, m);

  return val1 + val2;
}

int factorial(int n) {
  if(n == 1) {
    return 1;
  }
  
  return n * factorial(n-1);
}

int main() {
  // code here
  int n = 5;
  int m = 5;

  cout << gridWays(0, 0, n, m) << endl;


  // Better approach

  int num = factorial(n-1+m-1);
  int den = factorial(n-1) * factorial(m-1);

  cout << num / den << endl;

  return 0;
}

/*
    Complexities: 
        TIME: O(2 ^ (n + m))
*/