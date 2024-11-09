#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  list<pair<int,int>> *l;
  bool isUndirected;

public:
  Graph(int V, bool isUndirected = true) {
    this->V = V;
    l = new list<pair<int,int>>[V];
    this->isUndirected = isUndirected;
  }

  void addEdge(int u, int v, int wt) { // u ------ v
    l[u].push_back(make_pair(v, wt));
    if (isUndirected) {
      l[v].push_back(make_pair(u, wt));
    }
  }

  void primsAlgo(int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // wt, v -> min heap
    vector<bool> mst(V, false);

    pq.push(make_pair(0,src));
    int cost = 0;

    while(!pq.empty()){
      int u = pq.top().second;
      int wt = pq.top().first;
      pq.pop();

      if(!mst[u]){
        mst[u] = true;
        cost += wt;
        list<pair<int,int>> neighbours = l[u];
        for(pair<int,int> n : neighbours){
          int v = n.first;
          int currWt = n.second;
          pq.push(make_pair(currWt, v));
        }
      }
    }
    cout << cost << endl;
  }
};

int main() {
  // code here
  int V = 4;
  Graph graph(V, false);

  graph.addEdge(0,1,10);
  graph.addEdge(0,2,15);
  graph.addEdge(0,3,30);
  graph.addEdge(1,3,40);
  graph.addEdge(2,3,50);
 
  graph.primsAlgo(0);

  return 0;
}