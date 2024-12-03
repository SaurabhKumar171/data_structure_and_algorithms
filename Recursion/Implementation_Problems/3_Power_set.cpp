#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;

class Solution {
private:
    void createSubSets(int index, vector<int> list, vector<vector<int>>& ans, vector<int>& nums){
        
        if(index == nums.size()){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[index]);
        createSubSets(index+1, list, ans, nums);

        list.pop_back();
        createSubSets(index+1, list, ans, nums);
    }

public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> ans;

        vector<int> list;
        
        createSubSets(0, list, ans, nums);

        return ans;
    }
};