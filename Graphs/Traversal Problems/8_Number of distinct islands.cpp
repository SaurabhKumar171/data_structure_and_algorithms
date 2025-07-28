#include <iostream>
#include <vector>
#include <set>
using namespace std;

//Approach : O(n * m) time complexity , O(n * m) space complexity
class Solution {
   private:
    bool isValid(int r, int c, int n, int m) {
        return !(r < 0 || r >= n || c < 0 || c >= m);
    }

    void dfs(int r, int c, int rbase, int cbase, vector<vector<bool>> &vis, vector<vector<int>> &grid,
             vector<pair<int, int>>& temp) {
        int n = grid.size(), m = grid[0].size();

        vis[r][c] = true;
        temp.push_back({r - rbase, c - cbase});

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newRow = r + delRow[k];
            int newCol = c + delCol[k];

            if (isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1 &&
                !vis[newRow][newCol]){
                    dfs(newRow, newCol, rbase, cbase, vis, grid, temp);
                }
        }
    }

   public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> temp;
                    dfs(i, j, i, j, vis, grid, temp);
                    st.insert(temp);
                }
            }
        }

        return st.size();
    }
};
