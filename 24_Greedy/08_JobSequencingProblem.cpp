#include <bits/stdc++.h>
using namespace std;

class Job {
public:
  int index;
  int deadline;
  int profit;

  Job(int index, int deadline, int profit) {
    this->index = index;
    this->deadline = deadline;
    this->profit = profit;
  }
};

int maxProfit(vector<pair<int,int>> pairs) {
  int n = pairs.size();
  vector<Job> jobs;
  for(int i=0; i<n; i++){
    // Push back : we have to create an object and store it into a new variable and push while in case of emplace everthing is done by compiler
    jobs.emplace_back(i, pairs[i].first, pairs[i].second);
  }


  // Lambda function: function can be use in particular place once, and it cannot call by any other
  sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
    return a.profit > b.profit; // descending order
  }); // capture list

  cout << "Selecting Job" << jobs[0].index << endl;
  int profit = jobs[0].profit;
  int safeDeadline = 2;

  for(int i=1; i<n; i++){
    if(jobs[i].deadline >= safeDeadline){
      cout << "Selecting Job" << jobs[i].index << endl;
      profit += jobs[i].profit;
      safeDeadline = jobs[i].deadline++;
    }
  }

  return profit;
}

/*

bool compare(pair<int, int> p1, pair<int, int> p2) {
  return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs) {
  int n = jobs.size();
  sort(jobs.begin(), jobs.end(), compare);

  int profit = jobs[0].second;
  int safeDeadline = 2;

  for (int i = 1; i < jobs.size(); i++) {
    if (jobs[i].first >= safeDeadline) {
      profit += jobs[i].second;
      safeDeadline = jobs[i].first + 1;
    }
  }
  return profit;
}

*/

int main() {
  // code here
  int n = 4;

  // first -> deadline & seond -> profit
  vector<pair<int, int>> jobs(n, make_pair(0, 0));
  jobs[0] = make_pair(4, 20);
  jobs[1] = make_pair(1, 10);
  jobs[2] = make_pair(1, 40);
  jobs[3] = make_pair(1, 30);

  cout << maxProfit(jobs);

  return 0;
}

/*
    Maximize the total profit if only one job can be scheduled at a time

    JOB A = 4, 20
    JOB B = 1, 10
    JOB C = 1, 40
    JOB D = 1, 30

*/