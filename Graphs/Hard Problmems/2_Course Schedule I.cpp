#include <iostream>
#include <vector>
using namespace std;

//Approach : DFS - O(N + E) time complexity ,  O(N) space complexity
class Solution{
   private:
    bool dfs(int node, vector<vector<int>>& prerequisites, vector<bool>& vis,
             vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true;

        for (auto it : prerequisites[node]) {
            if (!vis[it]) {
                if (dfs(it, prerequisites, vis, pathVis)) return true;
            } else if (pathVis[it])
                return true;
        }

        pathVis[node] = false;
        return false;
    }
public:
    bool canFinish(int N, vector<vector<int>> arr) {
        vector<vector<int>> adjLs(N);

        for(int i = 0; i < arr.size(); i++){
            adjLs[arr[i][0]].push_back(arr[i][1]);
        }

        vector<bool> vis(N, false);
        vector<bool> pathVis(N, false);

        for (int i = 0; i < N; i++) {
            if (!vis[i])
                if (dfs(i, adjLs, vis, pathVis)) return false;
        }

        return true;
    }
};