
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:O(V*E) due to nested loops iterating through vertices and edges.
// Space Complexity:O(V) to store the distances array.
class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Adjacency list: node -> (neighbor, weight)
        vector<int> distances(V, 1e9);
        distances[S] = 0;
        
        for(int k = 1; k < V; k++){
            for (auto &edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                
                if(distances[u] != 1e9 && distances[v] > distances[u] + w){
                    distances[v] = distances[u] + w;
                }
            }
        }

        // relaxation to check negative cycle
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            
            if(distances[u] != 1e9 && distances[v] > distances[u] + w){
                return {-1};
            }
        }

        return distances;	
	}
};
