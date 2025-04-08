#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  list<int> *l;

  public:
  Graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }

  void addEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
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

  bool bfsPathHelper(int src, int dest) {
    vector<bool> visited(V,false);
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
      int u = q.front();
      q.pop();

      if(u == dest) {
        return true;
      }

      for(int v : l[u]) {
        if(!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    return false;
  }

  bool dfs(int src, int dest, vector<bool> &visited) {
    if(src == dest) return true;

    visited[src] = true;

    for(int v : l[src]) {
      if(!visited[v]) {
        if(dfs(v,dest,visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool hasPath(int src, int dest) {
    vector<bool> visited(V, false);
    return dfs(src,dest,visited);
  }
};

int main() {
  // code here
  Graph graph(7);

  // undirected graph
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(3, 4);
  graph.addEdge(3, 5);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);

  cout << graph.hasPath(0,4) << endl;
  cout << graph.bfsPathHelper(0,4) << endl;

  return 0;
}