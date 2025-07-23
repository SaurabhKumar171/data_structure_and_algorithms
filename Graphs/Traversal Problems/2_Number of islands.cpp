#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Approach :  O(V + E) time complexity , O(V) space complexity
class Solution {
   private:
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;

        return true;
    }

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid.size(), m = grid[0].size();

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            int r = cell.first, c = cell.second;

            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    int newRow = r + delRow;
                    int newCol = c + delCol;

                    if (isValid(newRow, newCol, n, m) && grid[newRow][newCol] == '1' &&
                        vis[newRow][newCol] == 0) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};
