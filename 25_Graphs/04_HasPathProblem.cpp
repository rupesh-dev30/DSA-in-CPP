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

  bool pathHelper(int src, int dest, vector<bool> &visited) {
    if (src == dest) {
      return true;
    }

    visited[src] = true;
    list<int> neighbours = l[src];

    for (int v : neighbours) {
      if (!visited[v]) {
        if (pathHelper(v, dest, visited)) {
          return true;
        }
      }
    }

    return false;
  }

  bool hasPath(int src, int dest) {
    vector<bool> visited(V, false);
    return pathHelper(src, dest, visited);
  }

  bool hasPathBFS(int src, int dest){
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
      int node = q.front();
      q.pop();

      if(node == dest) {
        return true;
      }

      for(int neighbour : l[node]){
        if(!visited[neighbour]){
          q.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
    return false;
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

  cout << graph.hasPath(5, 6) << endl;
  cout << graph.hasPathBFS(5, 6) << endl;


  return 0;
}