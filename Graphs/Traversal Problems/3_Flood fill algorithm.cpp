#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Approach :  O(n * m) time complexity , O(n * m) space complexity
class Solution {
   private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;

        return true;
    }

    void dfs(int sr, int sc, vector<vector<int>> &ans, int iniColor,
             int newColor, vector<vector<int>> &image) {
        ans[sr][sc] = newColor;

        int n = image.size(), m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];

            if (isValid(nrow, ncol, n, m) && image[nrow][ncol] == iniColor &&
                ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, iniColor, newColor, image);
            }
        }
    }

   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        if (iniColor != newColor) {
            dfs(sr, sc, ans, iniColor, newColor, image);
        }

        return ans;
    }
};
