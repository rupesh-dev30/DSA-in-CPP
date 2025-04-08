#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  list<int> *l;
  bool isUndirected;

public:
  Graph(int V, bool isUndirected = true) {
    this->V = V;
    l = new list<int>[V];
    this->isUndirected = isUndirected;
  }

  void addEdge(int u, int v) { // u ------ v
    l[u].push_back(v);
    if (isUndirected) {
      l[v].push_back(u);
    }
  }

  void print() {
    for (int u = 0; u < V; u++) {
      list<int> neighbours = l[u];
      cout << u << " : ";
      for (int v : neighbours) {
        cout << v << " ";
      }
      cout << endl;
    }
  }

  void indegree(vector<int> &indeg) {
    for(int u=0; u<V; u++) {
      for(int v : l[u]) {
        indeg[v]++;
      }
    }
  }
};

int main() {
  // code here
  int V = 6;
  Graph graph(V, false);

  graph.addEdge(2, 3);
  graph.addEdge(3, 1);
  graph.addEdge(4, 0);
  graph.addEdge(4, 1);
  graph.addEdge(5, 0);
  graph.addEdge(5, 2);

  vector<int> indeg(V,0);
  graph.indegree(indeg);

  for(int v : indeg) {
    cout << v << endl;
  }

  return 0;
}

/*
    Topological Sorting

      used for Directed Acyclic Graphs (DAG)

      Linear order of vetices such that for every u -> v, u comes before v in sequence
*/