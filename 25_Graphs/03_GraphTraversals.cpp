#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  list<int> *l;

public:
  Graph(int V) {
    this->V = V;
    l = new list<int>[V];

    /*
      int *arr;
      arr = new int[V]
    */
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

  void bfs() { // TC: O(V + E)
    queue<int> q;
    // bool *visited = new bool[V];
    vector<bool> visited(V, false);

    q.push(0);
    visited[0] = true;

    while (q.size() > 0) {
      int u = q.front(); // current vertex
      q.pop();

      cout << u << " ";

      list<int> neighbours = l[u];
      for (int v : neighbours) {
        if (!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    cout << endl;
  }

  void dfsHelper(int u, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    list<int> neighbours = l[u];
    for (int v : neighbours) {
      if(!visited[v]) {
        dfsHelper(v, visited);
      }
    }
  }

  void dfs(int V) {
    vector<bool> visited(V, false);
    dfsHelper(0, visited);
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

  // graph.print();

  // cout << "BFS Traversal: ";
  // graph.bfs();
  // cout << endl;

  graph.dfs(8);

  // graph.print();

  return 0;
}

/*
    If graph has a weight then

      list<pair<int,int>> [V]
*/

/*
    1. Breadth First Search (BFS)  -> Similar to Level Order Search (tree)
    2. Depth First Search (DFS)
*/