
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(k * 4α) (where N is the number of accounts and K is the maximum number of emails in an account)
// Space Complexity: O(k) for traversing the operators array and for each operator we are checking for 4 adjacent nodes and α is the inverse Ackermann function which is very slow growing function and for all practical purposes

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
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<int> ans;
        bool vis[n][m];
        memset(vis, false, sizeof vis);

        int cnt = 0;
        for (auto it : operators) {
            int r = it[0], c = it[1];

            if (vis[r][c]) {
                ans.push_back(cnt);
                continue;
            }

            vis[r][c] = true;
            cnt++;

            vector<int> delRow = {-1, 0, 1, 0};
            vector<int> delCol = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int adjRow = r + delRow[i];
                int adjCol = c + delCol[i];

                if (isValid(adjRow, adjCol, n, m) && vis[adjRow][adjCol] == true) {
                    int rowMajor = (r * m) + c;
                    int adjRowMajor = (adjRow * m) + adjCol;

                    if (ds.findUlitimateParent(rowMajor) !=
                        ds.findUlitimateParent(adjRowMajor)) {
                        cnt--;
                        ds.unionByRank(rowMajor, adjRowMajor);
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
