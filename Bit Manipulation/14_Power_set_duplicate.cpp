(T.C - {O(2 ^ n) * O(n)}, S.C - O(1)) class Solution
{
public:
    vector<vector<int>> powerSet(vector<int> &nums)
    {
        vector<vector<int>> result;

        int subsets = 1 << nums.size();

        for (int num = 0; num < subsets; num++)
        {
            vector<int> list;

            for (int j = 0; j < nums.size(); j++)
            {

                // check if ith bit is set
                if (num & (1 << j))
                {
                    list.push_back(nums[j]);
                }
            }

            result.push_back(list);
        }

        return result;
    }
};