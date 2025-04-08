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

  bool undirectedGraphHelper(int u, int parent, vector<bool> &visited) {
    visited[u] = true;

    for(int v : l[u]) {
      if(!visited[v]) {
        if(undirectedGraphHelper(v,u,visited)) {
          return true;
        }
      } else {
        if(v != parent) {
          return true;
        }
      }
    }

    return false;
  }

  bool isCycleUndirected() {
    vector<bool> visited(V,false);

    return undirectedGraphHelper(0,-1,visited);
  }

  bool bfs() {
    queue<pair<int,int>> q;
    vector<bool> visited(V,false);
    q.push({0,-1});
    visited[0] = true;

    while(!q.empty()) {
      pair<int,int> u = q.front();
      q.pop();

      for(int v : l[u.first]) {
        if(!visited[v]) {
          q.push({v,u.first});
          visited[v] = true;
        } else {
          if(v != u.second) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  // code here
  int V = 5;
  Graph graph(V);

  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(0,3);
  graph.addEdge(1,4);

  cout << graph.isCycleUndirected() << endl;
  cout << graph.bfs() << endl;


  return 0;
}