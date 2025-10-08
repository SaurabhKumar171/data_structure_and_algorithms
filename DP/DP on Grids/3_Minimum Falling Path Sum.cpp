#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
// Time Complexity:O(m*n) due to the memoization in the `func` function which ensures that each cell in the `dp` table is computed only once, and the outer loop in `minFallingPathSum` iterates `n` times.
// Space Complexity:O(m*n) due to the `dp` table which stores the intermediate results of size m*n, and the recursion stack can go up to O(m) in the worst case.
class Solution {
   private:
    int func(int r, int c, int m, int n, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        if (r == m - 1) {
            return matrix[r][c];
        }

        int bottomLeft = INT_MAX, bottomRight = INT_MAX, bottom = INT_MAX;
        if (c > 0) {
            bottomLeft = func(r + 1, c - 1, m, n, matrix, dp) + matrix[r][c];
        }

        if (c < n - 1) {
            bottomRight = func(r + 1, c + 1, m, n, matrix, dp) + matrix[r][c];
        }

        if (r < m - 1) {
            bottom = func(r + 1, c, m, n, matrix, dp) + matrix[r][c];
        }

        return dp[r][c] = min(bottomLeft, min(bottomRight, bottom));
    }

   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int val = func(0, i, m, n, matrix, dp);
            res = min(val, res);
        }
        return res;
    }
};


// Tabulation
// Time Complexity:O(m*n) due to the nested loops iterating through the matrix of size m x n.
// Space Complexity:O(m*n) due to the dp table of size m x n.
class Solution {
   private:
    int func(int m, int n, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {
        for (int i = m - 1; i >= 0; i--) {
            if (i == m - 1) {
                for (int j = n - 1; j >= 0; j--) {
                    dp[i][j] = matrix[i][j];
                }
                continue;
            }

            for (int j = n - 1; j >= 0; j--) {
                int bottomLeft = INT_MAX, bottomRight = INT_MAX,
                    bottom = INT_MAX;
                if (j > 0) bottomLeft = dp[i + 1][j - 1];

                if (j < n - 1) bottomRight = dp[i + 1][j + 1];

                bottom = dp[i + 1][j];

                dp[i][j] =
                    matrix[i][j] + min(bottomLeft, min(bottomRight, bottom));
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(dp[0][i], res);
        }
        return res;
    }

   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        return func(m, n, matrix, dp);
    }
};



// Space Optimization
// Time Complexity:O(m*n) due to the nested loops iterating through the matrix of size m x n.
// Space Complexity:O(n) due to the use of two 1D arrays (prev and temp) of size n each, instead of a 2D dp table.
class Solution {
   private:
    int func(int m, int n, vector<vector<int>>& matrix) {
        vector<int> prev(n);
        for (int i = m - 1; i >= 0; i--) {
            if (i == m - 1) {
                for (int j = n - 1; j >= 0; j--) {
                    prev[j] = matrix[i][j];
                }
                continue;
            }

            vector<int> temp(n);
            for (int j = n - 1; j >= 0; j--) {
                int bottomLeft = INT_MAX, bottomRight = INT_MAX,
                    bottom = INT_MAX;
                if (j > 0) bottomLeft = prev[j - 1];

                if (j < n - 1) bottomRight = prev[j + 1];

                bottom = prev[j];

                temp[j] =
                    matrix[i][j] + min(bottomLeft, min(bottomRight, bottom));
            }

            prev = temp;
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(prev[i], res);
        }
        return res;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        return func(m, n, matrix);   
    }
};