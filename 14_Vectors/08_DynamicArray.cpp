#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  vector<int> v = {1,2,3,4,5};

  v.push_back(6);

  v.pop_back();

  for(auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
  }

  return 0;
}