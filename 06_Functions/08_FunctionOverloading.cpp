#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b) {
  return a + b;
}

float sum(float a, float b) {
  return a + b;
}

double sum(double a, double b) {
  return a + b;
}

int main() {
  // code here

  cout << sum(4, 5) << endl;
  cout << sum(4.5f, 5.6f) << endl;
  cout << sum(4.5, 5.6) << endl;
  return 0;
}