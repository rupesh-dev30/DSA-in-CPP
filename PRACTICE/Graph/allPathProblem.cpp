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

  void pathHelper(int src, int dest, vector<bool> &visited, string path) {
    if(src == dest) {
      cout << path << dest << endl;
      return;
    }

    visited[src] = true;

    path += to_string(src);
    for(int v : l[src]) {
      if(!visited[v]) {
        pathHelper(v,dest,visited,path);
      }
    }
    path = path.substr(0,path.length()-1);
    visited[src] = false;
  }

  void printAllPaths(int src, int dest) {
    vector<bool> visited(V,false);

    string path = "";
    pathHelper(src,dest,visited,path);
  }

  void printAllPathBfs(int src, int dest) {
    queue<pair<int,string>> q;
    q.push({src,to_string(src)});

    while(!q.empty()) {
      auto curr = q.front();
      q.pop();

      int node = curr.first;
      string path = curr.second;

      if(node == dest) {
        cout << path << endl;
      }

      for(int v : l[node]) {
        // We avoid cycles by checking if 'v' is already in the path string
        // OR, better, track visited per path (not globally)
        if(path.find(to_string(v)) == string::npos) {
          q.push({v,path+to_string(v)});
        }
      }
    }
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
  graph.printAllPathBfs(5,1);

  return 0;
}

/*
  ALL PATHS PROBLEM

    Print all paths from src to dest for a directed graph
*/