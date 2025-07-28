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

    void dfs(int i, int j, vector<vector<char>>& mat,
        vector<vector<bool>>& vis) {
        int n = mat.size(), m = mat[0].size();
        mat[i][j] = '-';
        vis[i][j] = true;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            if (isValid(newRow, newCol, n, m) && mat[newRow][newCol] == 'O' &&
                !vis[newRow][newCol]){
                    dfs(newRow, newCol, mat, vis);
                }
        }
    }

   public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    !vis[i][j] && mat[i][j] == 'O') {
                    dfs(i, j, mat, vis);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if (mat[i][j] == '-') {
                    mat[i][j] = 'O';
                }
            }
        }

        return mat;
    }
};