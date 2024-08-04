#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {

    int n = nums.size();
    vector<int> sumLeft(n, 0);

    int lsum = 0;

    for(int i = 0; i < n; i++){
        lsum += nums[i];
        sumLeft[i] = lsum;
    }

    int leftSum;

    for(int i = 0; i < n; i++){
        if(i == 0){
            leftSum = 0;
        }
        else {
            leftSum = sumLeft[i-1];
        }

        int rightSum = sumLeft[n-1] - sumLeft[i];

        if(leftSum == rightSum){
            return i;
        }

    }

    return -1;
}