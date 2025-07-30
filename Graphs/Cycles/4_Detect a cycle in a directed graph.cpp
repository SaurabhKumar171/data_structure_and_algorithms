#include <iostream>
#include <vector>
using namespace std;

//Approach : DFS - O(V + E) time complexity ,  O(V + E) space complexity
class Solution {
   private:
    bool dfs(int node, vector<int> adj[], vector<bool>& vis,
             vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it])
                return true;
        }

        pathVis[node] = false;
        return false;
    }

   public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                if (dfs(i, adj, vis, pathVis)) return true;
        }

        return false;
    }
};


//Approach : BFS - O(V + E) time complexity ,  O(V + E) space complexity
class Solution {
   public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++){
            for(auto it: adj[i]) inDegree[it]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto it: adj[node]){
                inDegree[it]--;

                if(inDegree[it] == 0) q.push(it);
            }

            ans.push_back(node);
        }

        return ans.size() < V;
    }
};
