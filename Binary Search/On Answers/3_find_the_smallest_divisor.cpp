#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
    private:
    int calSum(vector<int> nums,int threshold){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
        sum += ceil((double)(nums[i]) / (double)(threshold));
        }

        return sum;
    }

    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        
        while(l <= h){

            int m = h + (l - h)/2;

            int currSum = calSum(nums, m);

            if(threshold < currSum){
            l = m +1;
            }
            else{
            h = m - 1;
            }

        }

        return l;        
        }
};