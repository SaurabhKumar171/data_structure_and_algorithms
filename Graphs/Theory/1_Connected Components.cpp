#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
   private:
    void bfs(int node, vector<int> adjList[], vector<int> &vis) {
        vis[node] = 1;

        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            for (auto adjNodes : adjList[i]) {
                if (vis[adjNodes] != 1) {
                    vis[adjNodes] = 1;
                    q.push(adjNodes);
                }
            }
        }
    }

    void dfs(int node, vector<int> adjList[], vector<int> &vis) {
        vis[node] = 1;

        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

   public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        int E = edges.size();

        vector<int> adjList[V];

        for (int i = 0; i < E; i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;

                bfs(i, adjList, vis);
            }
        }

        return cnt;
    }
};