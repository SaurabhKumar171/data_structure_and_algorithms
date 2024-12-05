#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    void getCombinations(int index, int sum, vector<int> &list, vector<vector<int>> &ans, vector<int> &nums, int cnt, int k, int n)
    {

        if (cnt == k && sum == n)
        {
            ans.push_back(list);
            return;
        }

        if ((cnt == k && sum != n) || cnt > k || index == nums.size())
            return;

        list.push_back(nums[index]);
        getCombinations(index + 1, sum + nums[index], list, ans, nums, cnt + 1, k, n);

        list.pop_back();
        getCombinations(index + 1, sum, list, ans, nums, cnt, k, n);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // your code goes here
        vector<int> list;
        vector<vector<int>> ans;

        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        getCombinations(0, 0, list, ans, nums, 0, k, n);

        return ans;
    }
};