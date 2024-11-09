#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int v;
  int wt;

  Edge(int v, int wt) {
    this->v = v;
    this->wt = wt;
  }
};

/*

The time complexity of the Bellman-Ford algorithm as implemented in the provided code is O(V * E), where V is the number of vertices and E is the number of edges in the graph. This is because the algorithm consists of V-1 iterations (the outer loop) over all vertices, and for each vertex, it iterates through all its edges. The inner loop iterates through the edges of each vertex, leading to a total of E edge relaxations across all vertices.

The space complexity of the algorithm is O(V). This is primarily due to the storage of the distance array `dist`, which holds the shortest distance from the source vertex to each of the V vertices. The graph itself is represented as an adjacency list, which can vary in space depending on the number of edges, but the main space usage in this algorithm comes from the distance array. Thus, the overall space complexity remains O(V).

*/

void bellmanFord(vector<vector<Edge>> graph, int V, int src) { // TC: O(V)
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  for (int i = 0; i < V - 1; i++) {
    for (int u = 0; u < V; u++) {
      for (Edge e : graph[u]) {
        if (dist[e.v] > dist[u] + e.wt) {
          dist[e.v] = dist[u] + e.wt;
        }
      }
    }
  }

  for (int i = 0; i < V; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}

int main() {
  // code here
  int V = 5;
  vector<vector<Edge>> graph(V);

  graph[0].push_back(Edge(1, 2));
  graph[0].push_back(Edge(2, 4));

  graph[1].push_back(Edge(2, -4));

  graph[2].push_back(Edge(3, 2));

  graph[3].push_back(Edge(4, 4));

  graph[4].push_back(Edge(1, -1));

  bellmanFord(graph, V, 0);

  return 0;
}

/*
  Bellman Ford ALgorithm

    Shortest path from src to all vertices for weighted graph with negative weight.

    NOTE: BF doesnt work for negative weight cycles. (cycles with overall negative weight)
*/