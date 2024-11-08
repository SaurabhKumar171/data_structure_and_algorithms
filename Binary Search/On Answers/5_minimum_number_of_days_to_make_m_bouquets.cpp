// Brute force ( Linear search )
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
private:
    bool possible(vector<int> &nums, int day, int m, int k) {
        int n = nums.size(); 
        int cnt = 0;
        int noOfB = 0;

        for(int i = 0; i< n; i++){
          if(nums[i] <= day){
            cnt++;
          }
          else{
            noOfB += (cnt/k);
            cnt = 0;
          }
        }
        noOfB += (cnt / k); 

        return noOfB >= m;
    }

public:
  int roseGarden(int n,vector<int> nums, int k, int m) {
   
    long long val = m * 1ll * k * 1ll; 
        
    if (val > n) return -1; 
    
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, nums[i]); 
        maxi = max(maxi, nums[i]); 
    }

   for(int i = mini; i <= maxi; i++){
      if(possible(nums, i, m, k))
        return i;
   }

   return -1;
  }
};


// Brute force Approach ( Binary search )
class Solution {
private:
    bool possible(vector<int> &nums, int day, int m, int k) {
        int n = nums.size(); 
        int cnt = 0;
        int noOfB = 0;

        for(int i = 0; i< n; i++){
          if(nums[i] <= day){
            cnt++;
          }
          else{
            noOfB += (cnt/k);
            cnt = 0;
          }
        }
        noOfB += (cnt / k); 

        return noOfB >= m;
    }

public:
    int minDays(vector<int>& nums, int m, int k) {
        
        int n = nums.size(); 
        long long val = m * 1ll * k * 1ll; 
            
        if (val > n) return -1; 
        
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]); 
            maxi = max(maxi, nums[i]); 
        }

        int left = mini, right = maxi, ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(possible(nums, mid, m, k)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};