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

  void bfsHelper(int u, vector<bool> &visited) {
    queue<int> q;
    q.push(u);

    visited[u] = true;

    while(!q.empty()) {
      int u = q.front();
      q.pop();

      cout << u << " ";

      for(int v: l[u]) {
        if(!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    cout << endl;
  }

  void bfs() {
    vector<bool> visited(V,false);
    int component = 1;
    for(int i=0; i<V; i++) {
      if(!visited[i]) {
        cout << "COMPONENT " << component++ << " : ";
        bfsHelper(i,visited);
        cout << endl;
      }
    }
  }

  void dfsHelper(int u, vector<bool> &visited) {
    cout << u << " ";
    visited[u] = true;
    for(int v : l[u]) {
      if(!visited[v]) {
        dfsHelper(v,visited);
      }
    }
  }

  void dfs() {
    vector<bool> visited(V,false); 
    int component = 1;

    for(int i=0; i<V; i++) {
      if(!visited[i]) {
        cout << "COMPONENT " << component++ << " : ";
        dfsHelper(i,visited);
        cout << endl;
      }
    }
  }
};

int main() {
  // code here
  Graph graph(10);

  // undirected graph
  graph.addEdge(0, 2);
  graph.addEdge(1, 6);
  graph.addEdge(2, 5);
  graph.addEdge(3, 4);
  graph.addEdge(3, 7);
  graph.addEdge(3, 8);
  graph.addEdge(4, 6);
  graph.addEdge(4, 9);

  graph.dfs();
  cout << endl;
  graph.bfs();

  return 0;
}