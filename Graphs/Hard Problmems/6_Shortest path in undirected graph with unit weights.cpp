#include <iostream>
#include <vector>
using namespace std;


// Form 1
//Approach : BFS - O(V + E) time complexity ,  O(V + E) space complexity
class Solution {
     private:
    void bfs(int N, vector<vector<int>>& adj, vector<int>& ans) {
        ans[0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                int subNode = it;
                int subWeight = 1;

                int totalDist = wt + subWeight;
                int shortestDistance = totalDist;

                if(ans[subNode] != -1 && ans[subNode] < shortestDistance) continue;
                
                ans[subNode] = shortestDistance;
                q.push({subNode, shortestDistance});
            }
        }
    }

  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<vector<int>> adj(N);

        for (int i = 0; i < edges.size(); i++) {
            int node = edges[i][0];
            int neighbor = edges[i][1];
            adj[node].push_back(neighbor);
            adj[neighbor].push_back(node);
        }

        vector<int> ans(N, -1);
        bfs(N, adj, ans);

        return ans;   
    }
};
