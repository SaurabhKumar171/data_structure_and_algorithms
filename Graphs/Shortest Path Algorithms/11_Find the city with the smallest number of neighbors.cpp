
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:O(n^3) due to the Floyd-Warshall algorithm and O(n^2) for checking distances
// Space Complexity:O(n^2) to store the adjacency matrix
class Solution {
   private:
    int INF = 1e9;

    void floydWarshall(int n, vector<vector<int>>& adjMatrix){
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        adjMatrix[i][j] = 0;
                    else
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
                }
            }
        }
    }

   public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        vector<vector<int>> adjMatrix(n, vector<int>(n, INF));
        for (auto it : edges) {
            int u = it[0], v = it[1], w = it[2];

            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w;
        }

        floydWarshall(n, adjMatrix);

        // Count the number of reachable cities from each city within the distanceThreshold.
        vector<int> reachableCitiesCount(n, 0);
        int minReachableCities = INF, cityIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] != INF && adjMatrix[i][j] <= distanceThreshold) {
                    reachableCitiesCount[i]++;
                }
            }

            if (minReachableCities >= reachableCitiesCount[i]) {
                cityIndex = i;
                minReachableCities = reachableCitiesCount[i];
            }
        }

        return cityIndex;
    }
};
