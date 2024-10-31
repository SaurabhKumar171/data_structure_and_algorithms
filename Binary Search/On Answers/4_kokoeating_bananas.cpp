// Brute force ( Linear search )
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution1 {
private:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int> &v, int hourly) {
        int totalH = 0;

        for(int i = 0; i < v.size(); i++){
            totalH += ceil((double)(v[i])/(double)(hourly));
        }

        return totalH;
    }


public:
int minimumRateToEatBananas(vector<int> nums, int h) {

        int maxi = findMax(nums);

        for(int i = 1; i <= maxi; i++){
            int requiredTime = calculateTotalHours(nums, i);
            if(requiredTime <= h){
                return i; 
            }
        }

        return maxi;
    }
};



// Binary search
class Solution {
private:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int> &v, int hourly) {
        int totalH = 0;

        for(int i = 0; i < v.size(); i++){
            totalH += ceil((double)(v[i])/(double)(hourly));
        }

        return totalH;
    }


public:
int minimumRateToEatBananas(vector<int> nums, int h) {

        int l = 1;
        int high = findMax(nums);

        while(l <= high){
            int m = l + (high - l)/2;
            int requiredTime = calculateTotalHours(nums, m);

            if(requiredTime <= h){
                high = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return l;
    }
};
