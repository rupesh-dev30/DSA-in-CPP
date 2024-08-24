#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  vector<int> v1;
  vector<int> v2 = {1, 2, 3, 4};
  vector<int> v3(5, -1);
  // 5 -> size filled with -1

  cout << "size: " << v2.size() << endl;
  cout << "capacity: " << v2.capacity() << endl;

  v2.push_back(5);

  cout << "size: " << v2.size() << endl;
  cout << "capacity: " << v2.capacity() << endl;

  v2.pop_back(); // delete from last

  return 0;
}

// Vectors: Like Dynamic arrays that can resize dynamically at runtime.
// They are stored contiguously in memory