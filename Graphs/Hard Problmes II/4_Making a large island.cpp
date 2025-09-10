
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Time Complexity: O(n*n) (where n is the size of the grid)
// Space Complexity: O(n*n) for DSU and O(1) for traversing the grid

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
   private:
    bool isValid(int r, int c, int n, int m) {
        return r < n && c < m && r >= 0 && c >= 0;
    }

    void addInitialIslands(vector<vector<int>>& grid, int n, DisjointSet& ds) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    for (int i = 0; i < 4; i++) {
                        int nr = r + delRow[i];
                        int nc = c + delCol[i];

                        if (isValid(nr, nc, n, n) && grid[nr][nc] == 1) {
                            int nodeNo = (r * n) + c;
                            int adjNodeNo = (nr * n) + nc;

                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
    }

public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        addInitialIslands(grid, n, ds);

        int ans = 0;

        bool noZeroes = true;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    noZeroes = false;

                    set<int> components;
                    for (int i = 0; i < 4; i++) {
                        int nr = r + delRow[i];
                        int nc = c + delCol[i];

                        if (isValid(nr, nc, n, n) && grid[nr][nc] == 1) {
                            int adjNodeNo = (nr * n) + nc;
                            int ultParent = ds.findUlitimateParent(adjNodeNo);
                            components.insert(ultParent);
                        }
                    }

                    int sizeTotal = 0;

                    for (auto it : components) {
                        sizeTotal += ds.size[it];
                    }
                    ans = max(ans, sizeTotal + 1);
                }
            }
        }

        if (noZeroes) return n * n;

        return ans;
    }
};