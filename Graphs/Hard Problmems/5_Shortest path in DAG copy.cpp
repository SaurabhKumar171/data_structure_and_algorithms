#include <iostream>
#include <vector>
using namespace std;


// Form 1
//Approach : BFS - O(V + E) time complexity ,  O(V + E) space complexity
class Solution {
   private:
    void topoSort(int N, vector<vector<pair<int, int>>>& adj, vector<int>& ans) {
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                int subNode = it.first;
                int subWeight = it.second;

                int totalDist = wt + subWeight;
                int shortestDistance = totalDist;

                if(ans[subNode] != -1 && ans[subNode] < shortestDistance) continue;
                
                ans[subNode] = shortestDistance;
                q.push({subNode, shortestDistance});
            }
        }
    }

   public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(N);

        for (int i = 0; i < edges.size(); i++) {
            int node = edges[i][0];
            int neighbor = edges[i][1];
            int weight = edges[i][2];

            adj[node].push_back({neighbor, weight});
        }

        vector<int> ans(N, -1);
        topoSort(N, adj, ans);
        ans[0] = 0;

        return ans;
    }
};
