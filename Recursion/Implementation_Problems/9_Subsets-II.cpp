#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

// Brute force Approcah (using set) : T.C - O(2^n), S.C - O(n)
class Solution
{
private:
    void getSubsets(int index, vector<int> &nums, vector<int> &list, set<vector<int>> &s)
    {

        if (index == nums.size())
        {
            s.insert(list);
            return;
        }

        list.push_back(nums[index]);
        getSubsets(index + 1, nums, list, s);

        list.pop_back();

        getSubsets(index + 1, nums, list, s);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> list;

        set<vector<int>> s;

        sort(nums.begin(), nums.end());

        getSubsets(0, nums, list, s);

        for (auto i : s)
        {
            ans.push_back(i);
        }

        return ans;
    }
};

// Optimal Approcah (Without using any extra space) : T.C - O(2^n * n), S.C - O(n)
class Solution
{
private:
    void getSubsets(int index, vector<vector<int>> &ans, vector<int> &nums, vector<int> &list)
    {

        if (index == nums.size())
        {
            ans.push_back(list);
            return;
        }

        list.push_back(nums[index]);
        getSubsets(index + 1, ans, nums, list);

        list.pop_back();

        for (int j = index + 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[index])
            {
                getSubsets(j, ans, nums, list);
                return;
            }
        }

        getSubsets(nums.size(), ans, nums, list);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> list;

        sort(nums.begin(), nums.end());

        getSubsets(0, ans, nums, list);

        return ans;
    }
};