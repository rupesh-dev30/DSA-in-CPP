#include <bits/stdc++.h>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2){
  return p1.first > p2.first;
}

int fractionalKnapsack(vector<int> value, vector<int> weight, int weigths) {
  int n = value.size();
  vector<pair<double,int>> ratio(n, make_pair(0.0, 0));  // pair (ratio, index)

  for(int i=0; i<n; i++){
    double temp = value[i] / weight[i];
    ratio[i] = make_pair(temp, i);
  }

  sort(ratio.begin(), ratio.end(), compare);

  int ans = 0;
  for(int i=0; i<n; i++) {
    int index = ratio[i].second;
    if(weight[index] <= weigths) {
      ans += value[index];
      weigths -= weight[index];
    } else {
      ans += ratio[i].first * weigths;
      weigths = 0;
      break;
    }
  }
  return ans;
}

int main() {
  // code here
  vector<int> value = {60, 100, 120};
  vector<int> weight = {10, 20, 30};
  int weights = 50;

  cout << fractionalKnapsack(value, weight, weights) << endl;

  return 0;
}

/*
    Put items in knapsack to get the maximum total value in the knapsack

    Note: Greedy  : Fractional Knapsack
          Dynamic : 0/1 Knapsack
*/