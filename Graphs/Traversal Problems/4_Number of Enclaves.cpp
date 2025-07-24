#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Approach :  O(n * m) time complexity , O(n * m) space complexity
class Solution {
 private:
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;

        return true;
    }

    void bfs(int i, int j, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        grid[i][j] = 0;

        queue<pair<int, int>> q;
        q.push({i, j});

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> i = q.front();
            q.pop();

            auto r = i.first, c = i.second;

            for (int k = 0; k < 4; k++) {
                int newRow = r + dRow[k];
                int newCol = c + dCol[k];

                if (isValid(newRow, newCol, n, m) &&
                    grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 0;
                    q.push({newRow, newCol});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) bfs(i, j, grid);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) cnt++;
            }
        }

        return cnt;        
    }
};