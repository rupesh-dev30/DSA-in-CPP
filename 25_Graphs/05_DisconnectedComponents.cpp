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

  void bfsHelper(int u, vector<bool> &visited) { // TC: O(V + E)
    queue<int> q;

    q.push(u);
    visited[u] = true;

    while (q.size() > 0) {
      int node = q.front(); // current vertex
      q.pop();

      cout << node << " ";

      list<int> neighbours = l[node];
      for (int v : neighbours) {
        if (!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    cout << endl;
  }

  void bfs(){
    vector<bool> visited(V, false);
    int component = 1;
    for(int i=0; i<V; i++){
      if(!visited[i]){
        cout << "Component " << component++ << ": ";
        bfsHelper(i, visited);
        cout << endl;
      }
    }
  }

  void dfsHelper(int u, vector<bool> &visited) {
    cout << u << " ";
    visited[u] = true;
    for (int v : l[u]) {
      if (!visited[v]) {
        dfsHelper(v, visited);
      }
    }
  }

  void dfs() {
    vector<bool> visited(V, false);
    int component = 1; // To label each component
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        cout << "Component " << component++ << ": ";
        dfsHelper(i, visited);
        cout << endl;
      }
    }
    cout << endl;
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
  graph.bfs();

  return 0;
}