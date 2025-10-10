#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution {
   private:
    int func(int i, int j1, int j2, int n, int m, vector<vector<int>>& matrix,
             vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        if (i == n - 1) {
            if (j1 == j2)
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }

        int maxi = INT_MIN;

        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;

                if (j1 == j2)
                    ans = matrix[i][j1] +
                          func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
                else
                    ans = matrix[i][j1] + matrix[i][j2] +
                          func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);

                maxi = max(maxi, ans);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

   public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        return func(0, 0, m - 1, n, m, matrix, dp);
    }
};

// Tabulation
class Solution {
   public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                if (j1 == j2)
                    dp[m - 1][j1][j2] = matrix[m - 1][j1];
                else
                    dp[m - 1][j1][j2] = matrix[m - 1][j1] + matrix[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = 0; j2 < n; j2++) {
                    int maxi = INT_MIN;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ans;

                            if (j1 == j2)
                                ans = matrix[i][j1];
                            else
                                ans = matrix[i][j1] + matrix[i][j2];

                            if (j1 + di >= 0 && j1 + di < n && j2 + dj >= 0 &&
                                j2 + dj < n)
                                ans += dp[i + 1][j1 + di][j2 + dj];
                            else
                                ans += -1e9;

                            maxi = max(maxi, ans);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};