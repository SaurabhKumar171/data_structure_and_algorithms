#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Approach : O(n * m) + O(n * m * 4) i.e ~ O(n * m) time complexity , O(n * m) + O(n * m) + O(n * m) space complexity
class Solution {
   private:
    bool isValid(int r, int c, int n, int m) {
        return !(r < 0 || r >= n || c < 0 || c >= m);
    }

   public:
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            pair<int, int> p = node.first;
            int dist = node.second;

            int r = p.first, c = p.second;

            vector<int> delRow = {-1, 0, 1, 0};
            vector<int> delCol = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int newRow = r + delRow[k];
                int newCol = c + delCol[k];

                if (isValid(newRow, newCol, n, m) &&
                    grid[newRow][newCol] != 1 && !vis[newRow][newCol]) {
                    ans[newRow][newCol] = dist + 1;
                    vis[newRow][newCol] = true;
                    q.push({{newRow, newCol}, dist + 1});
                }
            }
        }

        return ans;
    }
};