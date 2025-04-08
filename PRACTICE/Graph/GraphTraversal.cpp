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

    void bfs() {
      queue<int> q;
      vector<bool> visited(V,false);
    
      q.push(0);
      visited[0] = true;

      while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int v : l[u]) {
          if(!visited[v]) {
            q.push(v);
            visited[v] = true;
          }
        }
      }
      cout << endl;
    }

    void dfs(int V) {
      vector<bool> visited(V,false);

      dfsHelper(0,visited);
    }

    void dfsHelper(int u, vector<bool> &visited){
      visited[u] = true;

      cout << u << " ";

      for(int v : l[u]) {
        if(!visited[v]) {
          dfsHelper(v,visited);
        }
      }
    }
};

int main() {
  // code here
  Graph graph(7);
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(3, 4);
  graph.addEdge(3, 5);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);

  graph.bfs();
  cout << endl;

  graph.dfs(7);

  return 0;
}