class Solution {
private:
    void generatePermutaions(vector<int>& ds, vector<int>& freq, vector<int>& nums, vector<vector<int>>& ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                generatePermutaions(ds, freq, nums, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);

        generatePermutaions(ds, freq, nums, ans);
        return ans;
    }
};