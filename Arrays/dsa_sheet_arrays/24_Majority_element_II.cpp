#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std; 

//better approach
vector<int> majorityElement(vector<int>& nums) {

    int n = nums.size();

    unordered_map<int, int> umap;

    for(int i = 0; i < n; i++){
        umap[nums[i]]++;
    }

    vector<int> res;

    for(auto it = umap.begin(); it != umap.end(); ++it){
        // cout << key << " " << value <<endl;
        if(it->second > n/3)
            res.push_back(it->first);
    }
  
    return res;
}

//optimal approach
vector<int> majorityElementOptimalApproach(vector<int>& nums) {

    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;

    vector<int> res;

    for(int i = 0; i < n; i++){

        if(cnt1 == 0 && ele2 != nums[i]){
            ele1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && ele1 != nums[i]){
            ele2 = nums[i];
            cnt2 = 1;
        }
        else if(ele1 == nums[i]){
            cnt1++;
        }
        else if(ele2 == nums[i]){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == ele1) cnt1++;
        else if(nums[i] == ele2) cnt2++;
    }

    int mini = n / 3;
    if (cnt1 > mini) res.push_back(ele1);
    if (cnt2 > mini) res.push_back(ele2);

    return res;
}