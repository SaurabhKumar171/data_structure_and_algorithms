
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

// Form 2 : Disjoint Set (Kruskal's Algorithm)
// Time Complexity: O(ElogE)+O(Eα(V))≈O(ElogE) (where E is the number of edges in the graph and V is the number of nodes in the graph)
// O(ElogE) is for sorting the edges and O(Eα(V)) is for


// Space Complexity: O(V+E) (where V is the number of nodes in the graph and E is the number of edges in the graph)
// O(V) is for the parent, rank and size array used in the Disjoint Set
// O(E) is for storing all the edges

class DisjointSet {
   private:
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
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0], wt = it[1], node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int sum = 0;

        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUlitimateParent(u) != ds.findUlitimateParent(v)) {
                sum += wt;
                ds.unionBySize(u, v);
            }
        }

        return sum;
    }
};
