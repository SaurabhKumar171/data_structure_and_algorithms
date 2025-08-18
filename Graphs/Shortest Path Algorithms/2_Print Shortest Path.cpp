
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

// Form 1 : Using Priority Queue
// Time Complexity:O(m + n*log(n)),where n is the number of nodes and m is the number of edges.
// Space Complexity:O(n + m), where n is the number of nodes and m is the number of edges.

using P = pair<int, int>;

class Solution {
   public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        vector<int> distances(n + 1, 1e9);
        vector<int> parent(n + 1);

        minHeap.push({0, 1});

        for (int i = 0; i < parent.size(); i++) parent[i] = i;

        distances[1] = 0;

        while (!minHeap.empty()) {
            auto [dist, node] = minHeap.top();
            minHeap.pop();

            for (auto it : adj[node]) {
                int totalDist = dist + it.second;
                int subNode = it.first;

                if (totalDist < distances[subNode]) {
                    parent[subNode] = node;
                    distances[subNode] = totalDist;
                    minHeap.push({totalDist, subNode});
                }
            }
        }

        if (distances[n] == 1e9) return {-1};

        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), distances[n]);

        return path;
    }
};