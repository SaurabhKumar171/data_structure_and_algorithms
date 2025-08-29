
#include <iostream>
#include <vector>
using namespace std;


// Time Complexity:O(E log V) where E is the number of roads and V is the number of nodes, due to the priority queue operations
// Space Complexity:O(V + E) where V is the number of nodes and E is the number of roads, due to adjacency list, distances and ways vectors.

using P = pair<long long, int>;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        // Adjacency list: node -> (neighbor, weight)
        vector<vector<pair<int,int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> ways(n, 0);
        vector<long long> distances(n, LLONG_MAX);

        pq.push({0, 0});
        distances[0] = 0, ways[0] = 1;

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            for(auto it: adj[node]){
                int next = it.first, wt = it.second;

                long long newDist = dist + wt;
                if(newDist < distances[next]){
                    distances[next] = newDist;
                    ways[next] = ways[node];
                    pq.push({newDist, next});
                }
                else if(newDist == distances[next]){
                    ways[next] = (ways[node] + ways[next])%mod;
                }
            }
        }

        return ways[n - 1];
    }
};