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

   void pathHelper(int src, int dest, vector<bool> &visited, string &path) {
    if(src == dest){
      cout << path << dest << endl;
      return;
    }

    visited[src] = true;
    // path.push_back(src);
    path += to_string(src);
    list<int> neighbours = l[src];

    for(int v : neighbours) {
      if(!visited[v]) {
        pathHelper(v, dest, visited, path);
      }
    }

    path = path.substr(0, path.size() - 1);
    visited[src] = false;
  }

  void printAllPaths(int src, int dest){
    vector<bool> visited(V, false);
    string path = "";
    pathHelper(src,dest,visited,path);
  }
};

int main() {
  // code here
  int V = 6;
  Graph graph(V, false);

  graph.addEdge(0,3);
  graph.addEdge(2,3);
  graph.addEdge(3,1);
  graph.addEdge(4,0);
  graph.addEdge(4,1);
  graph.addEdge(5,0);
  graph.addEdge(5,2);

  graph.printAllPaths(5, 1);

  return 0;
}

/*
  ALL PATHS PROBLEM

    Print all paths from src to dest for a directed graph
*/