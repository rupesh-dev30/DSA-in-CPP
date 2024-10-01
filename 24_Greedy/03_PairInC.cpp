#include <bits/stdc++.h>
using namespace std;

/*
    Pairs in C++
      STL container to store 2 objects
*/

bool compare(pair<int,int> p1, pair<int,int> p2) {
  return p1.second < p2.second;  //ascending order
  // return p1.second > p2.second;  //descending order
}

int main() {
  // code here
  vector<int> start = {0, 1, 3};
  vector<int> end = {9, 2, 4};

  vector<pair<int,int>> activities(3, make_pair(0,0));
  activities[0] = make_pair(0,9);
  activities[1] = make_pair(1,2);
  activities[2] = make_pair(3,4);

  for(int i=0; i<activities.size(); i++) {
    cout << activities[i].first << " " << activities[i].second << endl;
  }

  sort(activities.begin(), activities.end(), compare);

  cout << "After Sorting" << endl;

  for(int i=0; i<activities.size(); i++) {
    cout << activities[i].first << " " << activities[i].second << endl;
  }

  return 0;
}

/*
    Select the maximum number of activities that can be performed by a single person.
    (a person can work on one activity at a time)

    SIMILAR QUESTION:
      Maximum meeting in a room (LEETCODE)
*/