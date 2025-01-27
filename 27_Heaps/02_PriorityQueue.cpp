#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  
  // MAX HEAP
  priority_queue<int> pq;

  // MIN HEAP
  priority_queue<int, vector<int>, greater<int>> pq1;

  
  pq.push(23); // O(logn)
  pq.push(40);
  pq.push(12);
  pq.push(9);


  while(!pq.empty()) {
    cout << pq.top() << endl;  // O(1)
    pq.pop(); // O(logn)
  }

  return 0;
}