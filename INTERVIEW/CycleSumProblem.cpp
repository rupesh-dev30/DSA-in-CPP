#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int largestSumCycle(vector<int>& edges) {
    int n = edges.size();
    vector<int> indegree(n, 0);

    // Step 1: Calculate indegree of each node
    for (int i = 0; i < n; i++) {
        if (edges[i] != -1) {
            indegree[edges[i]]++;
        }
    }

    // Step 2: Remove non-cycle nodes using topological pruning
    queue<int> q;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int next = edges[node];
        if (next == -1) continue;

        indegree[next]--;
        if (indegree[next] == 0) {
            q.push(next);
            visited[next] = true;
        }
    }

    // Step 3: Traverse remaining (cycle) nodes and compute cycle sums
    int maxSum = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int current = i;
        int sum = 0;

        // Traverse the cycle and sum the nodes
        while (!visited[current]) {
            visited[current] = true;
            sum += current;
            current = edges[current];
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> edges(n);
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }

    int result = largestSumCycle(edges);
    cout << result << endl;

    return 0;
}
