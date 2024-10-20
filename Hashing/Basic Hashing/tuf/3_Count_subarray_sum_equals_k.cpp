#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int subarrayCnt = 0;

        for(int i = 0; i < n; i++){  

            int cnt = 0;
            int sum = 0;

            for(int j = i; j < n; j++){  
                sum += nums[j];

                if(sum == k){
                    subarrayCnt++;
                }   
            }
        }
     
        return subarrayCnt;
    }
};