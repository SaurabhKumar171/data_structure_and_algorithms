
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countPaths(int n, vector<vector<int>> &roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

        // count of distance, distance
        vector<pair<int, int>> distances(n, {0, 1e9});

        distances[0] = {1, 0};
        q.push({0, 0});

        while (!q.empty()) {
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto it : adj[node]) {
                int subNode = it.first;
                int subWt = it.second;

                int newWt = subWt + dist;

                if (newWt < distances[subNode].second) {
                    // Found shorter path
                    distances[subNode] = {distances[node].first, newWt};
                    q.push({newWt, subNode});
                }
                else if (newWt == distances[subNode].second) {
                    // Found another shortest path
                    distances[subNode].first = (distances[subNode].first + distances[node].first) % MOD;
                }
            }
        }

        return distances[n - 1].first;
    }
};