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

  void addEdge(int u, int v) { // u ------ v
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

  bool isBipartite() {
    vector<bool> visited(V,false);
    queue<int> q;
    vector<int> color(V,-1);

    q.push(0);
    color[0] = 0;
    visited[0] = true;

    while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(int v : l[node]) {
        if(!visited[v]) {
          q.push(v);
          color[v] = !color[node];
          visited[v] = true;
        } else {
          if(color[v] == color[node]) {
            return false;
          }
        }
      }
    }
    return true;
  }

  bool dfs(int u, vector<int> &color, vector<bool> &visited) {
    visited[u] = true;

    for(int v : l[u]) {
      if(!visited[v]) {
        color[v] = !color[u];
        dfs(v,color,visited);
      } else {
        if(color[v] == color[u]) {
          return false;
        }
      }
    }
    return true;
  }

  bool isPartiteDfs() {
    vector<bool> visited(V,false);
    vector<int> color(V,-1);

    for(int i=0; i<V; i++) {
      if(!visited[i]) {
        color[i] = 0;
        if(!dfs(i,color,visited)) {
          return false;
        }
      }
    }

    return true;
  }
};

int main() {
  // code here
  int V = 5;
  Graph graph(V);

  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(1,3);
  graph.addEdge(2,4);
  // graph.addEdge(3,4);

  cout << graph.isBipartite() << endl;
  cout << graph.isPartiteDfs() << endl;

  return 0;
}


/*
    Bipartite Graph

      Acyclic : TRUE
      Even Cycle : TRUE
      Odd Cycle : False
*/