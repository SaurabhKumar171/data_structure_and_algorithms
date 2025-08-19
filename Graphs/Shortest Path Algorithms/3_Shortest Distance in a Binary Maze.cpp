
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;


// Time Complexity: O(N*M) (where N and M are the dimensions of the grid)
// A simple BFS traversal takes O(V+E) time where V and E represent the number of cells and number of edges.
// Because, V = N*M and E = 4*N*M, the overall time complexity is O(N*M).

// Space Complexity: O(N*M) The distance array takes O(N*M) space and the queue space can go upto O(N*M) in the worst case.
class Solution {
    bool isValid(int r, int c, int n, int m) {
        if (r >= 0 && c >= 0 && r < n && c < m) return true;

        return false;
    }

   public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distances(n, vector<int>(m, 1e9));

        distances[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while (!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first, col = q.front().second.second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if (isValid(nr, nc, n, m) && grid[nr][nc] == 1 &&
                    dist + 1 < distances[nr][nc]) {
                    distances[nr][nc] = dist + 1;

                    if (nr == destination.first && nc == destination.second) {
                        return dist + 1;
                    }

                    q.push({dist + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};