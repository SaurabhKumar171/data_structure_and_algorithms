// Optimal Soln (T.C - { O(n)}, S.C - O(1))
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // your code goes here
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }

        return res;
    }
};