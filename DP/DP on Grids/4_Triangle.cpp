#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
// Time Complexity:O(m*m) where m is the number of rows in the triangle, due to the memoization avoiding recomputation of overlapping subproblems in the recursive calls to func.
// Space Complexity:O(m*m) due to the dp table of size m*m used for memoization and the recursion stack space which can go up to m in the worst case.
class Solution {
   private:
    int func(int r, int c, int m, vector<vector<int>>& triangle,
             vector<vector<int>>& dp) {
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        if (r == m - 1) {
            return triangle[r][c];
        }

        int bottomRight = func(r + 1, c + 1, m, triangle, dp) + triangle[r][c];

        int bottom = func(r + 1, c, m, triangle, dp) + triangle[r][c];

        return dp[r][c] = min(bottomRight, bottom);
    }

   public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(triangle[i].size(), -1);
        }

        int val = func(0, 0, m, triangle, dp);

        return val;
    }
};



// Tabulation
// Time Complexity:The time complexity is O(m^2) due to nested loops iterating through the triangle's rows and elements.
// Space Complexity:The space complexity is O(m^2) due to the 'dp' vector of vectors which stores minimum path sums.
class Solution {
   private:
    int func(int m, vector<vector<int>>& triangle,
             vector<vector<int>>& dp) {
        for (int i = m - 1; i >= 0; i--) {
            if (i == m - 1) {
                for (int j = triangle[i].size() - 1; j >= 0; j--) {
                    dp[i][j] = triangle[i][j];
                }
                continue;
            }

            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                int bottomRight = dp[i + 1][j + 1];
                int bottom = dp[i + 1][j];

                dp[i][j] =
                    triangle[i][j] + min(bottomRight, bottom);
            }
        }

        return dp[0][0];
    }

   public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));

        return func(m, triangle, dp);
    }
};



// Space Optimization
// Time Complexity:O(m*m) where m is the number of rows in the triangle, due to the nested loops iterating through the triangle's rows and elements.
// Space Complexity:O(m) due to the use of two 1D arrays (prev and temp) of size m each, instead of a 2D dp table.
class Solution {
   private:
    int func(int m, vector<vector<int>>& triangle) {
        vector<int> prev(m);
        for (int i = m - 1; i >= 0; i--) {
            if (i == m - 1) {
                for (int j = i; j >= 0; j--) {
                    prev[j] = triangle[i][j];
                }
                continue;
            }

            vector<int> temp(m);
            for (int j = i; j >= 0; j--) {
                int bottomRight = prev[j + 1];
                int bottom = prev[j];

                temp[j] = triangle[i][j] + min(bottomRight, bottom);
            }

            prev = temp;
        }

        return prev[0];
    }

   public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));

        return func(m, triangle);
    }
};