#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;

class Solution {
private:
    void generateUniqueCombinations(int index, vector<int> list, vector<vector<int>>& ans, int sum, vector<int> candidates){

        if(index == candidates.size() || sum < 0) return;

        if(sum == 0){
            ans.push_back(list);
            return;
        }

        list.push_back(candidates[index]);
        generateUniqueCombinations(index, list, ans, sum - candidates[index], candidates);

        list.pop_back();
        generateUniqueCombinations(index + 1, list, ans, sum, candidates);
    } 

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> list;
        vector<vector<int>> ans;

        generateUniqueCombinations(0, list, ans, target, candidates);

        return ans;
    }
};