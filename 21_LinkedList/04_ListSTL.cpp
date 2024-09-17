#include <bits/stdc++.h>
using namespace std;

/*
    Iterators in C++ are objects that allow you to traverse through the elements of a container (like arrays, vectors, list, etc) in a sequential manner
*/

void printList(list<int> ll) {
  list<int>::iterator it;
  for (it = ll.begin(); it != ll.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  // code here
  list<int> ll; // vector<int> arr

  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.push_back(5);

  printList(ll);
  cout << ll.size() << endl;
  cout << ll.front() << endl;
  cout << ll.back() << endl;

  ll.pop_front();
  printList(ll);
  ll.pop_back();
  printList(ll);

  return 0;
}