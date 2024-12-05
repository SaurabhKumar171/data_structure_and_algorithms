#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    void subsetSum(int index, vector<int> &ans, vector<int> &nums, int sum)
    {

        if (index == nums.size())
        {
            ans.push_back(sum);
            return;
        }

        subsetSum(index + 1, ans, nums, sum + nums[index]);

        subsetSum(index + 1, ans, nums, sum);
    }

public:
    vector<int> subsetSums(vector<int> &nums)
    {
        // your code goes here
        vector<int> ans;
        vector<int> list;

        subsetSum(0, ans, nums, 0);

        return ans;
    }
};