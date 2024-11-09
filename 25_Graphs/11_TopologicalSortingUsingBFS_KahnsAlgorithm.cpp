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

  void calcInDegree(vector<int> &indeg) {
    for (int u = 0; u < V; u++) {
      list<int> neighbours = l[u];
      for (int v : neighbours) {
        indeg[v]++;
      }
    }
  }

  void topoSortKahnAlgo() {
    vector<int> indeg(V, 0);
    calcInDegree(indeg);

    queue<int> q;

    for (int i = 0; i < V; i++) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      cout << curr << " ";
      list<int> neighbours = l[curr];
      for (int v : neighbours) {
        indeg[v]--;
        if (indeg[v] == 0) {
          q.push(v);
        }
      }
    }
    cout << endl;
  }
};

int main() {
  // code here
  int V = 6;
  Graph graph(V, false);

  graph.addEdge(2, 3);
  graph.addEdge(3, 1);
  graph.addEdge(4, 0);
  graph.addEdge(4, 1);
  graph.addEdge(5, 0);
  graph.addEdge(5, 2);

  graph.topoSortKahnAlgo();

  return 0;
}

/*
      Topological Sorting

        a DAG has atleast one vertex with in-degree 0 and alteast one vertex with out-degree 0


        Steps:
          1. Push value with indegree 0 in queue
          2. while(!q.empty()) ->
                a. pop the value from queue
                b. decrease indegree of all its neighbours by 1
                c. if indegree of any neighbour becomes 0, push it in queue
*/