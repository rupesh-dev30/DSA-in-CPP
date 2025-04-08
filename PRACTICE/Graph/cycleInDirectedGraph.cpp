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

  bool directedCycleHelper(int src, vector<bool> &visited, vector<bool> &recPath){
    visited[src] = true;
    recPath[src] = true;

    list<int> neighbours = l[src];
    for(int v : neighbours) {
      if(!visited[v]) {
        if(directedCycleHelper(v, visited, recPath)){
          return true;
        }
      } else {
        if(recPath[v]){
          return true;
        }
      }
    } 
    recPath[src] = false;
    return false;
  }

  bool isCycleDirected() {
    vector<bool> visited(V, false);
    vector<bool> recPath(V, false);

    for(int i=0; i<V; i++) {
      if(!visited[i]){
        if(directedCycleHelper(i, visited, recPath)){
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  // code here
  int V = 5;
  Graph graph(V, false);

  graph.addEdge(1, 0);
  graph.addEdge(0, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 0);

  cout << graph.isCycleDirected() << endl;

  return 0;
}