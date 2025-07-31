#include <iostream>
#include <vector>
using namespace std;

//Approach : DFS - O(V + E) time complexity ,  O(V) space complexity
class Solution {
   private:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
             vector<bool>& pathVis, vector<int>& check) {
        vis[node] = true;
        pathVis[node] = true;
        check[node] = 0;


        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, check)) return true;
            } else if (pathVis[it])
                return true;
        }

        check[node] = 1;
        pathVis[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);
        vector<int> check(V, 0); 
        vector<int> safeNodes; 

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, adj, vis, pathVis, check);
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};