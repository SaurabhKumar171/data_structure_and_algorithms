// Brute force Soln - I (T.C - { O(2n)}, S.C - O(n) + O(n))

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (auto i : mpp)
        {
            if (i.second == 1)
            {
                res.push_back(i.first);
            }
        }

        return res;
    }
};