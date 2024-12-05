#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    void func(int index, vector<int> &list, int sum, vector<vector<int>> &ans, vector<int> &candidates)
    {

        if (sum == 0)
        {
            ans.push_back(list);
            return;
        }

        if (sum < 0 || index == candidates.size())
            return;

        list.push_back(candidates[index]);

        func(index + 1, list, sum - candidates[index], ans, candidates);

        list.pop_back();

        for (int j = index + 1; j < candidates.size(); j++)
        {
            if (candidates[j] != candidates[index])
            {
                func(j, list, sum, ans, candidates);
                break;
            }
        }

        // int j = index + 1;
        // while((j < candidates.size()) && candidates[index] == candidates[j]){
        //     j++;
        // }

        // func(j, list, sum, ans, candidates);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // your code goes here
        sort(candidates.begin(), candidates.end());

        vector<int> list;
        vector<vector<int>> ans;

        func(0, list, target, ans, candidates);

        return ans;
    }
};