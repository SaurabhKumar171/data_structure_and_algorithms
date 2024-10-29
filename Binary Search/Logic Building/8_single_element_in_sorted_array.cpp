#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        int l = 0;
        int h = nums.size()-1;

        while(l <= h){

            int m = l + (h-l)/2;

            if(l == h) return nums[l];

            if(m%2 != 0){
                if(m > l && nums[m-1] == nums[m]){
                    l = m + 1;
                }
                else if(m < h && nums[m+1] == nums[m]){
                    h = m - 1;
                }
                else{
                    return nums[m];
                }
            }
            else{
                if(m < h && nums[m] == nums[m+1]){
                    l = m+2;
                }
                else if(m > l && nums[m] == nums[m-1]){
                    h = m - 1;
                }
                else{
                    return nums[m];
                }
            }
            
        }

        return 0;      
    }
};