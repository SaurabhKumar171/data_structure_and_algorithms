#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
using namespace std;

// Optimal Approach  O(n * log(m) + n * log(max-min))
class Solution {
private:
    int countPartitions(vector<int> a, int maxSum){

        int cntSubrray = 1;
        int currentSum = 0;

        for(int i = 0; i < a.size(); i++){
            if((currentSum + a[i]) <= maxSum){
                currentSum += a[i];
            }
            else{
                cntSubrray++;
                currentSum = a[i];
            }
        }

        return cntSubrray;
    }

public:
    int largestSubarraySumMinimized(vector<int> &a, int k) {
        
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        while(low <= high){
            int m = (low + high)/2;

            int subArrayCnt = countPartitions(a, m);

            if(subArrayCnt > k){
                low = m + 1;
            }
            else{
                high = m - 1;
            }
        }

        return low;
    }
};