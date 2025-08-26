
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Adjacency list: node -> (neighbor, weight)
        vector<vector<pair<int,int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // dist[i] = shortest distance from 0 to i
        vector<long long> dist(n, LLONG_MAX);
        // ways[i] = number of shortest paths from 0 to i
        vector<int> ways(n, 0);

        // Min-heap (distance, node)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue; // stale state

            for (auto [next, weight] : adj[node]) {
                long long newDist = d + weight;

                if (newDist < dist[next]) {
                    // Found a shorter path
                    dist[next] = newDist;
                    ways[next] = ways[node]; // inherit path count
                    pq.push({newDist, next});
                }
                else if (newDist == dist[next]) {
                    // Found an additional shortest path
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];       
    }
};