#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int u;
  int v;
  int wt;

  Edge(int u, int v, int wt) {
    this->u = u;
    this->v = v;
    this->wt = wt;
  }
};

class Graph {
public:
  vector<Edge> edges;
  int V;
  vector<int> parent;
  vector<int> rank;

  Graph(int V) {
    this->V = V;
    for (int i = 0; i < V; i++) {
      parent.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]); // Path compression
  }

  void unionByRank(int u, int v) {
    int parentU = find(u);
    int parentV = find(v);
    if (parentU != parentV) {
      if (rank[parentU] < rank[parentV]) {
        parent[parentU] = parentV;
      } else if (rank[parentU] > rank[parentV]) {
        parent[parentV] = parentU;
      } else {
        parent[parentV] = parentU;
        rank[parentU]++;
      }
    }
  }

  void addEdge(int u, int v, int wt) {
    edges.push_back(Edge(u, v, wt));
  }

  void kruskals() {
    int minCost = 0;
    int cnt = 0;
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
      return a.wt < b.wt;
    });

    for (int i = 0; i < edges.size() && cnt < V - 1; i++) {
      Edge e = edges[i];
      int parentU = find(e.u);
      int parentV = find(e.v);

      if (parentU != parentV) {
        unionByRank(parentU, parentV);
        minCost += e.wt;
        cnt++;
      }
    }
    cout << "Minimum cost of the MST = " << minCost << endl;
  }
};

int main() {
  Graph graph(4);
  graph.addEdge(0, 1, 10);
  graph.addEdge(0, 2, 15);
  graph.addEdge(0, 3, 30);
  graph.addEdge(1, 3, 40);
  graph.addEdge(2, 3, 50);

  graph.kruskals();

  return 0;
}

/*
    Greedy Approach for MST

      1. Sort all the edge (basis of edge weight)
      2. Start from the first edge and add it to the MST if it does not form a cycle with the MST already formed.
      3. Repeat step 2 until all the edges are added to the MST.

*/