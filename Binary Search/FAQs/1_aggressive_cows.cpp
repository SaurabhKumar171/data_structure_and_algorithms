// Brute force ( Linear search )
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
private:
    bool canWePlace(vector<int> &nums, int dist, int cows){
        int n = nums.size();

        int cntCows = 1;

        int last = nums[0];

        for(int i = 1; i < n; i++){ 
            if(nums[i] - last >= dist){
                cntCows++;
                last = nums[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int limit = nums[n-1] - nums[0];

        for(int i = 1; i <= limit; i++){
            if(canWePlace(nums, i, k) == false){
                return (i - 1);
            }
        }

        return limit;
    }
};

// Optimal Approach ( Binary search )
class Solution {
private:
    bool canWePlace(vector<int> &nums, int dist, int cows){
        int n = nums.size();

        int cntCows = 1;

        int last = nums[0];

        for(int i = 1; i < n; i++){ 
            if(nums[i] - last >= dist){
                cntCows++;
                last = nums[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 1;
        int high = nums[n-1] - nums[0];

        while(low <= high){
            int mid = low + (high - low)/2;

            if(canWePlace(nums, mid, k) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }        
        }
        return high;
    }
};


// Line 3-4: Suggest renaming 'cntCows' to 'cowCount' for clarity
// Line 17: Improve formatting for readability
// Line 21: Suggest adding a comment explaining the binary search process
// Line 19: Suggest renaming 'last' to 'lastPosition' for better clarity
