#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std; 

vector<int> majorityElement(vector<int>& nums) {

    int n = nums.size();

    unordered_map<int, int> umap;

    for(int i = 0; i < n; i++){
        umap[nums[i]]++;
    }

    vector<int> res;

    for(auto& [key, value]: umap){
        // cout << key << " " << value <<endl;
        if(value > n/3)
            res.push_back(key);
    }

    return res;
}