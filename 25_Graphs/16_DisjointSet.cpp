#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
  int n;
  vector<int> parent; // leader
  vector<int> rank;

  DisjointSet(int n) {
    this->n = n;

    for (int i = 0; i < n; i++) {
      parent.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    }

    // return find(parent[x]);
    return parent[x] = find(parent[x]); // path compression
  }

  void unionByRank(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (rank[parentA] == rank[parentB]) {
      parent[parentB] = parentA;
      rank[parentA]++;
    } else if (rank[parentA] > rank[parentB]) {
      parent[parentB] = parentA;
    } else {
      parent[parentA] = parentB;
    }
  }

  void getInfo() {
    for (int i = 0; i < n; i++) {
      cout << i << ": " << parent[i] << " , " << rank[i] << endl;
    }
  }
};

int main() {
  // code here
  DisjointSet d(6);
  d.unionByRank(0, 2);
  cout << d.find(2) << endl;
  d.unionByRank(1, 3);
  d.unionByRank(2, 5);
  d.unionByRank(0, 3);
  cout << d.find(2) << endl;
  d.unionByRank(0, 4);

  d.getInfo();

  return 0;
}