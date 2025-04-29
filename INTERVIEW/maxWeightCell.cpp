#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum weight cell
int maxWeightCell(int n, vector<int> &edge) {
    vector<int> weight(n, 0); // weight[i] will store sum of indices pointing to i

    // Traverse all cells
    for (int i = 0; i < n; i++) {
        if (edge[i] != -1) {
            weight[edge[i]] += i; // add index i to the destination cell's weight
        }
    }

    int maxWeight = INT_MIN;
    int resultNode = -1;

    // Find the node with maximum weight (if tie, pick highest index)
    for (int i = 0; i < n; i++) {
        if (weight[i] >= maxWeight) {
            maxWeight = weight[i];
            resultNode = i;
        }
    }

    return resultNode;
}

int main() {
    int n;
    cin >> n; // number of cells

    vector<int> edge(n);
    for (int i = 0; i < n; i++) {
        cin >> edge[i]; // destination cell for each cell
    }

    int result = maxWeightCell(n, edge);
    cout << result << endl;

    return 0;
}
