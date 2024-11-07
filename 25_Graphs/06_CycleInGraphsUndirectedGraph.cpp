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

  bool undirectedCycleHelper(int src, int parent, vector<bool> &visited){
    visited[src] = true;

    list<int> neighbours = l[src];

    for(int v : neighbours){
      if(!visited[v]){
        if(undirectedCycleHelper(v, src, visited)){
          return true;
        }
      } else {
        if(v != parent){
          return true;
        }
      }
    }
    return false;
  }

  bool isCycleUndirected() {
    vector<bool> visited(V, false);

    return undirectedCycleHelper(0, -1, visited);
  }
};

int main() {
  // code here
  int V = 5;
  Graph graph(V);

  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(0,3);
  graph.addEdge(1,2);
  graph.addEdge(3,4);

  cout << graph.isCycleUndirected() << endl;

  return 0;
}