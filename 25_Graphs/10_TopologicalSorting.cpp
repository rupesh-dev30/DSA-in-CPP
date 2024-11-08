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

  void topoHelper(int src, vector<bool> &visited, stack<int> &s) {
    visited[src] = true;

    list<int> neightbours = l[src];
    for (int v : neightbours) {
      if (!visited[v]) {
        topoHelper(v, visited, s);
      }
    }

    s.push(src);
  }

  void topologicalSort() {
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        topoHelper(i, visited, s);
      }
    }

    // Printing Topological Order
    while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << endl;
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

  graph.topologicalSort();

  return 0;
}

/*
    Topological Sorting

      used for Directed Acyclic Graphs (DAG)

      Linear order of vetices such that for every u -> v, u comes before v in sequence
*/