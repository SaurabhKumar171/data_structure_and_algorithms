#include <iostream>
#include <vector>
using namespace std;

//Approach : O(V + E) time complexity ,  O(V + E) space complexity
class Solution{
private:
    bool dfs(int node, vector<int> adj[], vector<bool>& vis, int prev){
        vis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]){ if(dfs(it, adj, vis, node)) return true;}
            else if(it != prev) return true;
        }

        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        int ans = false;

        for(int i = 0; i < V; i++){
            if(vis[i]) continue;
            ans = dfs(i, adj, vis, -1);
            if(ans) break;
        }

        return ans;
    }
};