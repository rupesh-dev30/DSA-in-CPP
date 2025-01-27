#include <bits/stdc++.h>
using namespace std;

class Student { // "<" overload
public:
  string name;
  int marks;

  Student(string name, int marks) {
    this->name = name;
    this->marks = marks;
  }

  bool operator<(const Student &obj) const {
    return this->marks < obj.marks; // Default heap (c++) : MAX Heap
  }
};

struct ComparePair {
  bool operator()(pair<string, int> &p1, pair<string, int> &p2) {
    return p1.second < p2.second; // MAX HEAP
  }
};

int main() {
  // code here

  /*
      ERROR: PQ dont know on what basis it can sort

      priority_queue<Student> pq;

      pq.push(Student("Rupesh", 90));
      pq.push(Student("Ritesh", 100));
      pq.push(Student("Rishab", 95));

      while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
      }

  */

  // CLASS BASED
  priority_queue<Student> pq;

  pq.push(Student("Rupesh", 90));
  pq.push(Student("Ritesh", 100));
  pq.push(Student("Rishab", 95));

  cout << "Class" << endl;

  while (!pq.empty()) {
    cout << pq.top().name << ", " << pq.top().marks << endl;
    pq.pop();
  }

  // PAIR BASED
  // priority_queue<pair<string,int>> pq1;  // Default: maxHeap: on the basis of first
  priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq1;
  pq1.push(make_pair("Rupesh", 90));
  pq1.push(make_pair("Ritesh", 100));
  pq1.push(make_pair("Rishab", 95));

  cout << "Pair" << endl;

  while (!pq1.empty()) {
    cout << pq1.top().first << ", " << pq1.top().second << endl;
    pq1.pop();
  }

  return 0;
}