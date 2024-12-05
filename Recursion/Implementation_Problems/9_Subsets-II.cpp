#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

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