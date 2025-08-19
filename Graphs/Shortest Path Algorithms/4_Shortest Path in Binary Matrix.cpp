
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
class Solution {
    bool isValid(int r, int c, int n, int m) {
        if (r >= 0 && c >= 0 && r < n && c < m) return true;

        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};
        if (grid[0][0] == 1) return -1;
        if (source.first == destination.first &&
            source.second == destination.second)
            return 1;
            
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distances(n, vector<int>(m, 1e9));

        distances[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});
        
        vector<int> delRow = {-1, 0, 1};
        vector<int> delCol = {-1, 0, 1};
        while (!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first, col = q.front().second.second;

            q.pop();

            for (int i = 0; i < delRow.size(); i++) {
                for (int j = 0; j < delCol.size(); j++) {
                    int nr = row + delRow[i];
                    int nc = col + delCol[j];

                    if (isValid(nr, nc, n, m) && grid[nr][nc] == 0 &&
                        dist + 1 < distances[nr][nc]) {
                        distances[nr][nc] = dist + 1;
  
                        if (nr == destination.first && nc == destination.second) {
                            return dist + 1;
                        }

                        q.push({dist + 1, {nr, nc}});
                    }
                }
            }
        }

        return -1;       
    }
};