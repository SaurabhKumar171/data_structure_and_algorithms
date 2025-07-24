#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Approach :  O(n * m * 4) i.e ~ O(n * m) time complexity , O(n * m) + O(n * m) space complexity
class Solution {
   private:
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;

        return true;
    }

    void bfs(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& vis,
             vector<vector<int>>& grid, int& minTime) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            pair<int, int> p = node.first;
            int time = node.second, r = p.first, c = p.second;

            minTime = max(minTime, time);

            for (int k = 0; k < 4; k++) {
                int newRow = r + dRow[k];
                int newCol = c + dCol[k];

                if (isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 0 &&
                    grid[newRow][newCol] == 1) {
                    vis[newRow][newCol] = 1; // means orange rotted
                    q.push({{newRow, newCol}, time + 1});
                }
            }
        }
    }

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Enqueue all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int minTime = 0;
        bfs(q, vis, grid, minTime);

        // Check if any fresh orange was unreachable
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 1) {
                    return -1;
                }
            }
        }

        return minTime;
    }
};