
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

// Form 1 : Prim's Algorithm using Priority Queue
// Time Complexity: O(ElogE) (where E is the number of edges in the graph)
// In the worst case, the min-heap will store all the E edges, and insertion operation on the min-heap takes O(logE) time taking overall O(ElogE) time.
// Space Complexity: O(E + V) (where V is the number of nodes in the graph)
// The min-heap will store all edges in worst-case taking O(E) space and the visited array takes O(V) space.

class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<int> vis(V, 0);
        vector<pair<int, int>> mst;
        int sum = 0;

        pq.push({0, 0, -1});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int wt = top[0];
            int node = top[1];
            int parent = top[2];

            if (!vis[node]) {
                if (parent != -1) {
                    mst.push_back({parent, node});
                    sum += wt;
                }

                vis[node] = 1;

                for (auto it : adj[node]) {
                    int neighNode = it[0], neighWt = it[1];
                    if (!vis[neighNode]) {
                        pq.push({neighWt, neighNode, node});
                    }
                }
            }
        }

        return sum;
    }
};
