#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  int target = 9;
  vector<int> arr = {1, 2, 7, 11, 15, 5, 9};

  unordered_map<int, int> mp;
  for (int i = 0; i < arr.size(); i++) {
    int comp = target - arr[i];
    if (mp.count(comp)) {
      cout << mp[comp] << " " << i << endl;
      break;
    }

    mp[arr[i]] = i;
  }

  return 0;
}