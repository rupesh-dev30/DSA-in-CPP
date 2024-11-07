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

  bool isBipartiteGraph() {
    // bool *visited = new bool[V];
    vector<bool> visited(V, false); //we can do without this, check color[i] == -1, which means not visited
    queue<int> q;
    vector<int> color(V, -1);

    q.push(0);
    visited[0] = true;
    color[0] = 0;

    while(!q.empty()){
      int curr = q.front();
      q.pop();
      list<int> neighbours = l[curr];

      for(int v : neighbours) {
        if(!visited[v]) {
          visited[v] = true;
          color[v] = !color[curr];
          q.push(v);
        } else {
          if(color[v] == color[curr]){
            return false;
          }
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
  graph.addEdge(3,4);

  cout << graph.isBipartiteGraph();

  return 0;
}


/*
    Bipartite Graph

      Acyclic : TRUE
      Even Cycle : TRUE
      Odd Cycle : False
*/