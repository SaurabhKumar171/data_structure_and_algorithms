#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// Brute Force Approach : O(n*k) time complexity, O(1) space complexity
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& arr, int k) {
            int i = 0, n = arr.size();
    
            vector<int> store;
            while(i <= n - k){
              int maxi = INT_MIN;
              int j = i;
    
              while(j < i + k){
                maxi = max(maxi, arr[j]);
                j++;
              }
    
              store.push_back(maxi);
              i++;
            }
    
            return store;        
        }
    };




// Optimal Approach : O(n) time complexity, O(n) space complexity
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> list;
            int n = nums.size();
    
            for(int i = 0; i < n; i++){
                if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
    
                while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    
                dq.push_back(i);
    
                if(i >= k - 1) list.push_back(nums[dq.front()]);
            }
    
            return list;
        }
    };