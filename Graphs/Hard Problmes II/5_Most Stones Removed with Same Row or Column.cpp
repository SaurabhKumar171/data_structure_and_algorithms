
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n * α(n)) (where n is the number of stones and α is the Inverse Ackermann function)
// Space Complexity: O(n) for DSU and O(n) for the map
class DisjointSet {
   public:
    vector<int> rank, size, parent;

   public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUlitimateParent(int node) {
        if (node == parent[node]) return node;

        // Backtracking for path compression
        parent[node] = findUlitimateParent(parent[node]);
        return parent[node];
    }

    bool find(int u, int v) {
        return findUlitimateParent(u) == findUlitimateParent(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUlitimateParent(u);
        int ulp_v = findUlitimateParent(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUlitimateParent(u);
        int ulp_v = findUlitimateParent(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(it[0], maxRow);
            maxCol = max(it[1], maxCol);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            ds.unionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUlitimateParent(it.first) == it.first) {
                cnt++;
            }
        }

        return n - cnt;        
    }
};