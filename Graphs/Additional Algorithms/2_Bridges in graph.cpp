
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(V + 2E) (where E represent the number of edges). A single DFS traversal is made taking an O(V+E) time.
// Space Complexity: O(V + 2E) for adjacency list, O(V) for visited, tin and low arrays

class Solution {
   private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin,
             vector<int>& disc, vector<vector<int>>& adj,
             vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = disc[node] = timer;
        timer++;

        for(auto it: adj[node]){
            if(it == parent ) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, tin, disc, adj, bridges);
                disc[node] = min(disc[node], disc[it]);

                // node ----- it
                if(disc[it] > tin[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                disc[node] = min(disc[node], disc[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> disc(n);

        vector<vector<int>> bridges;

        dfs(0, -1, vis, tin, disc, adj, bridges);
        return bridges;  
    }
};