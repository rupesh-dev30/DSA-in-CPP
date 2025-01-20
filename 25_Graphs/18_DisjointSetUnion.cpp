/*
    Disjoint Set Union (DSU), also known as Union-Find, is an efficient data structure used for solving problems related to connectivity and grouping. It's commonly used in competitive programming (CP) for problems that require tracking and merging disjoint sets or components, such as in Kruskal's algorithm for finding the Minimum Spanning Tree (MST).

    Key Operations

      1. Find: 
        - Determines the representative or root of the set containing a particular element.
        - Efficiently implemented with path compression, which flattens the structure of the tree during queries to speed up future operations.

      2. Union: 
        - Merges two sets containing two different elements.
        - Efficiently implemented with union by rank/size, which ensures that smaller trees are merged under larger trees to keep the structure balanced and reduce the time complexity.

      DSU Data Structure

      The structure typically uses:
      - Parent Array: `parent[i]` points to the parent of element `i`. If `parent[i] = i`, then `i` is a root.
      - Rank/Size Array: `rank[i]` (or `size[i]`) is used to track the height or size of the tree rooted at `i`. This helps in optimizing the union operation.

      
      Time Complexity
      - Both Find and Union operations can be performed in nearly constant time, i.e., O(α(N)), where α is the inverse Ackermann function, which grows very slowly, so for all practical purposes, it's close to constant time.

      DSU with Path Compression and Union by Rank

Here’s how DSU is implemented:

*/

#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent, size;
    
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            // Path compression: make the structure flat
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank/size: Attach the smaller tree to the larger one
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 5;  // Number of elements
    DSU dsu(n);

    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    cout << dsu.connected(0, 2) << endl;  // 1 (true)
    cout << dsu.connected(0, 3) << endl;  // 0 (false)
    dsu.union_sets(3, 4);
    dsu.union_sets(2, 4);
    cout << dsu.connected(0, 4) << endl;  // 1 (true)

    return 0;
}

/*

    Important Points
    1. Path Compression: Helps to reduce the tree depth, ensuring that the structure remains nearly flat.
    2. Union by Rank/Size: Helps to keep the tree balanced, thus reducing the height and ensuring faster operations.
    3. Connected Query: You can efficiently check if two elements belong to the same set using the `find` operation.

    Applications in Competitive Programming
    - MST (Minimum Spanning Tree): Used in Kruskal’s algorithm to detect cycles and form a spanning tree.
    - Connected Components: To check whether two nodes are in the same connected component.
    - Network Connectivity: Tracking groups of connected components in a network.
    - Dynamic Connectivity: Efficiently handling queries about connectivity over time as edges are added or removed.

*/
