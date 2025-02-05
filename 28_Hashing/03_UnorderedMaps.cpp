#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<string, int> mp;

  mp["China"] = 150;
  mp["India"] = 150;
  mp["US"] = 50;
  mp["Nepal"] = 10;

  // cout << mp["India"] << endl;

  for (pair<string, int> p : mp) {
    cout << "Country: " << p.first << " Population: " << p.second << endl;
  }

  // mp.erase("Nepal");

  if(mp.count("Nepal")) { // return 1 -> if exist else 0
    cout << "Nepal is in the map" << endl;
  } else {
    cout << "Nepal is not in the map" << endl;
  }

  return 0;
}

// RED BLACK TREE