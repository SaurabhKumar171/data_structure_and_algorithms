// Optimal Soln - I (T.C - { O(n*32)}, S.C - O(1))
class Solution
{
public:
    int singleNumberII(vector<int> &nums)
    {
        int res = 0;
        for (int bitIndex = 0; bitIndex < 32; bitIndex++)
        {
            int cnt = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] & (1 << bitIndex))
                    cnt++;
            }

            if (cnt % 3 == 1)
                res = res | (1 << bitIndex);
        }

        return res;
    }
};

// Optimal Soln - II (T.C - { O(nlogn)}, S.C - O(1))
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // your code goes here
        sort(nums.begin(), nums.end());

        int res = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i++)
        {

            if (nums[i - 1] != nums[i])
            {
                return nums[i - 1];
            }
            else if (nums[i + 1] != nums[i])
            {
                return nums[i + 1];
            }
            else
            {
                i += 2;
            }
        }

        return res;
    }
};

// Optimal Soln - II (T.C - { O(n)}, S.C - O(1))
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }

        return ones;
    }
};