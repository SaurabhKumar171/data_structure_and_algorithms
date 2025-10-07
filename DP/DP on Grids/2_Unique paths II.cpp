#include <vector>
using namespace std;

// Recursion + Memoization
// Time Complexity:The time complexity is O(2^(m+n)) because each call to `func` can make two recursive calls, leading to an exponential number of calls. The function explores all possible paths from the top-left to the bottom-right corner.
// Space Complexity:The space complexity is O(m+n) due to the maximum depth of the recursion stack, which can be at most m+n in the worst-case scenario (when the path is a straight line).
class Solution {
   private:
    int func(int r, int c, int m, int n, vector<vector<int>>& matrix) {
        if (r == m - 1 && c == n - 1) {
            if(matrix[r][c] == 0) return 1;
            // else if(matrix[r][c] == 1) return 0;
        }

        int cnt1 = 0;
        if (r + 1 < m && matrix[r + 1][c] == 0) {
            cnt1 = func(r + 1, c, m, n, matrix);
        }

        int cnt2 = 0;
        if (c + 1 < n && matrix[r][c + 1] == 0) {
            cnt2 = func(r, c + 1, m, n, matrix);
        }

        return cnt1 + cnt2;
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[0][0] == 1) return 0;

        int cnt = func(0, 0, m, n, matrix);
        return cnt;
    }
};


// Tabulation
// Time Complexity:O(m*n) due to the nested loops iterating through the matrix of size m x n.
// Space Complexity:O(m*n) due to the dp table of size m x n.
class Solution {
   private:
    int func(int m, int n, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0 && matrix[i][j] == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                if (matrix[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                int up = 0, left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n));

        int cnt = func(m, n, matrix, dp);
        return cnt;
    }
};



// Space Optimization
// Time Complexity:The time complexity is O(m*n) due to the nested loops iterating through the matrix.
// Space Complexity:The space complexity is O(n) due to the usage of two vectors of size n.
class Solution {
   private:
    int func(int m, int n, vector<vector<int>>& matrix) {
        
        vector<int> prev(n);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                if (matrix[i][j] == 1) {
                    temp[j] = 0;
                    continue;
                }

                int up = 0, left = 0;
                if (i > 0) up = prev[j];
                if (j > 0) left = temp[j - 1];

                temp[j] = up + left;
            }
            prev = temp;
        }

        return prev[n - 1];
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[0][0] == 1) return 0;

        int cnt = func(m, n, matrix);
        return cnt;
    }
};