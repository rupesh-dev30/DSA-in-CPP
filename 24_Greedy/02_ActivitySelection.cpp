#include <bits/stdc++.h>
using namespace std;

int maxActivity(vector<int> start, vector<int> end) {
  cout << "A0\n";
  int count = 1;
  int currEndTime = end[0];

  for (int i = 1; i <= start.size(); i++) {
    if (start[i] >= currEndTime) { //non-overlapping
      cout << "A" << i << endl;
      count++;
      currEndTime = end[i];
    }
  }
  return count;
}

int main() {
  // code here
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> end = {2, 4, 6, 7, 9, 9};

  cout << maxActivity(start, end) << endl;

  return 0;
}

/*
    Select the maximum number of activities that can be performed by a single person.
    (a person can work on one activity at a time)

    SIMILAR QUESTION:
      Maximum meeting in a room (LEETCODE)
*/