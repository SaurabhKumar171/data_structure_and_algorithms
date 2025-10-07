#include <vector>
using namespace std;

// Recursion + Memoization
// Time Complexity:O(m*n) due to visiting each cell of the m x n grid once because of memoization.
// Space Complexity:O(m*n) due to the dp table of size m x n and the recursion stack space in the worst case.

class Solution {
   private:
    int func(int r, int c, int m, int n,
             vector<vector<int>>& dp) {
        if (dp[r][c] != -1) return dp[r][c];

        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        int cnt1 = 0;
        if (r + 1 < m) {
            cnt1 = func(r + 1, c, m, n, dp);
        }

        int cnt2 = 0;
        if (c + 1 < n) {
            cnt2 = func(r, c + 1, m, n, dp);
        }

        return dp[r][c] = cnt1 + cnt2;
    }

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int cnt = func(0, 0, m, n, dp);
        return cnt;
    }
};


// Tabulation
// Time Complexity:O(m*n) due to the nested loops iterating through the m x n grid.
// Space Complexity:O(m*n) because of the dp vector of size m x n used to store intermediate results.
class Solution {
   private:
    int func(int m, int n, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                int left = 0;
                if (j - 1 >= 0) left = dp[i][j - 1];

                int top = 0;
                if (i - 1 >= 0) top = dp[i - 1][j];

                dp[i][j] = left + top;
            }
        }

        return dp[m - 1][n - 1];
    }

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int cnt = func(m, n, dp);
        return cnt;
    }
};

// Space Optimization
// Time Complexity:O(m*n) due to nested loops iterating up to m and n, respectively, plus O(n) for initialising vectors
// Space Complexity:O(n) because the space used by the vectors 'prev' and 'temp' scales linearly with n.
class Solution {
   private:
    int func(int m, int n) {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                int top = 0, left = 0;

                if (i > 0) top = prev[j];
                if (j > 0) left = temp[j - 1];

                temp[j] = top + left;
            }

            prev = temp;
        }

        return prev[n - 1];
    }

   public:
    int uniquePaths(int m, int n) {
        int cnt = func(m, n);
        return cnt;
    }
};