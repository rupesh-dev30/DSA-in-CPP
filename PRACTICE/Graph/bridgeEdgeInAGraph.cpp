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

  void bridgeSolveDFS(int node, int c, int d, vector<int> &visited) {
    visited[node] = true;

    for(int v : l[node]) {
      if(!visited[v] && !(node == c && v == d) && !(node == d && v == c)) {
        bridgeSolveDFS(v,c,d,visited);
      }
    }
  }

  bool bridge(int c, int d) {
    vector<int> visited(V,0);
    bridgeSolveDFS(c,c,d,visited);

    return !visited[d];
  }
};

int main() {
  // code here
  int V = 6;
  Graph graph(V, true);

  graph.addEdge(1, 0);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(0, 3);
  graph.addEdge(3, 4);

  cout << graph.bridge(0,2) << endl;

  return 0;
}