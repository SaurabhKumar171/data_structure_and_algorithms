#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

// Form 1 : Using Priority Queue
// Time Complexity:O((V+E)logV), where V is the number of vertices and E is the number of edges.
// Space Complexity:O(V), where V is the number of vertices, for storing distances and the priority queue.
class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        vector<int> distances(V, 1e9);
        q.push({0, S});

        while (!q.empty()) {
            int node = q.top().second;
            int dist = q.top().first;
            q.pop();

            if (dist > distances[node]) continue;

            for (auto it : adj[node]) {
                int subNode = it[0];
                int subWeight = it[1];

                int totalDist = dist + subWeight;
                if (totalDist < distances[subNode]) {
                    distances[subNode] = totalDist;
                    q.push({totalDist, subNode});
                }
            }
        }

        distances[S] = 0;

        return distances;
    }
};

// Form 2 : Using Set
// Time Complexity:O((V+E)logV) where V is the number of vertices and E is the number of edges
// Space Complexity:O(V) due to the distances vector and the set.
class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> distances(V, 1e9);

        st.insert({0, S});
        distances[S] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dist = it.first;
            st.erase(it);

            for (auto it : adj[node]) {
                int subNode = it[0];
                int subWeight = it[1];

                int totalDist = dist + subWeight;
                if (totalDist < distances[subNode]) {
                    if (distances[subNode] != 1e9)
                        st.erase({distances[subNode], subNode});

                    distances[subNode] = totalDist;
                    st.insert({totalDist, subNode});
                }
            }
        }

        return distances;
    }
};