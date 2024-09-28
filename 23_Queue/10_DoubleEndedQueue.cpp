#include <bits/stdc++.h>
using namespace std;

int main() {
  // code here
  deque<int> d;

  d.push_front(2);
  d.push_front(1);

  d.push_back(3);
  d.push_back(4);

  cout << d.front() << endl;
  cout << d.back() << endl;

  while(!d.empty()){
    cout << d.front() << " ";
    d.pop_front();
  }
  
  return 0;
}


/*
    Double Ended Queue

      Deque in C++
        - push_back()
        - push_front()
        - pop_back()
        - pop_front()
        - front()
        - back()
        
*/