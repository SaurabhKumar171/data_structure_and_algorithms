#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// Better approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    //  vector<int>res{-1, -1}; 
     int n = nums.size();
     unordered_map<int, int> mp;

     for(int i = 0; i < n; i++){
        int k = target - nums[i];

        if(mp.find(k) != mp.end()){
            return {mp[k], i}; 
        }
        else{
            mp[nums[i]] = i;
        }
     }

      return {-1, -1}; 
    }
};

// Optimal Approach
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

     int n = nums.size();

     vector<vector<int>> elementIndex;

     for(int i = 0; i < n; i++){
        elementIndex.push_back({nums[i], i});
     }

     sort(elementIndex.begin(), elementIndex.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
     });

     int left = 0;
     int right = n - 1;

     while(left < right){

        int sum = elementIndex[left][0] + elementIndex[right][0];

        if(sum == target){
            return {elementIndex[left][1], elementIndex[right][1]};
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
     }

      return {-1, -1}; 
    }
};