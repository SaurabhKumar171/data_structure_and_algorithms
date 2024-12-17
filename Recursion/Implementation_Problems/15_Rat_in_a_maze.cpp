
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    void place(int r, int c, vector<vector<int>> &grid, string str, vector<string> &ans, int n)
    {

        if (grid[r][c] == 0)
            return;
        if (r == n - 1 && c == n - 1)
        {
            ans.push_back(str);
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = 0;

        if (r < n - 1)
        {
            str += 'D';
            place(r + 1, c, grid, str, ans, n);
            str.pop_back();
        }
        if (r > 0)
        {
            str += 'U';
            place(r - 1, c, grid, str, ans, n);
            str.pop_back();
        }
        if (c < n - 1)
        {
            str += 'R';
            place(r, c + 1, grid, str, ans, n);
            str.pop_back();
        }
        if (c > 0)
        {
            str += 'L';
            place(r, c - 1, grid, str, ans, n);
            str.pop_back();
        }

        grid[r][c] = temp;
    }

public:
    vector<string> findPath(vector<vector<int>> &grid)
    {
        // your code goes here
        vector<string> ans;

        place(0, 0, grid, "", ans, grid.size());

        return ans;
    }
};