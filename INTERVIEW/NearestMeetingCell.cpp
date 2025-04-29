#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate distance from a starting node to all reachable nodes
vector<int> getDistances(int start, vector<int> &edge) {
    int n = edge.size();
    vector<int> dist(n, -1);
    int d = 0;
    while (start != -1 && dist[start] == -1) {
        dist[start] = d;
        d++;
        start = edge[start];
    }
    return dist;
}

int nearestMeetingCell(int n, vector<int> &edge, int c1, int c2) {
    vector<int> dist1 = getDistances(c1, edge);
    vector<int> dist2 = getDistances(c2, edge);

    int minDist = INT_MAX;
    int answer = -1;

    for (int i = 0; i < n; i++) {
        if (dist1[i] != -1 && dist2[i] != -1) {
            int maxDist = max(dist1[i], dist2[i]);
            if (maxDist < minDist) {
                minDist = maxDist;
                answer = i;
            } else if (maxDist == minDist && i < answer) {
                answer = i;
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> edge(n);
    for (int i = 0; i < n; i++) {
        cin >> edge[i];
    }

    int c1, c2;
    cin >> c1 >> c2;

    int result = nearestMeetingCell(n, edge, c1, c2);
    cout << result << endl;

    return 0;
}
