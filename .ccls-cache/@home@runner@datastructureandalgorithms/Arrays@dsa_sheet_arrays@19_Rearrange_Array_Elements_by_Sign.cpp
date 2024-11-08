#include <iostream>
#include <vector>
using namespace std; 

vector<int> rearrangeArray(vector<int>& nums) {

    int n = nums.size();
    int posIndex = 0;
    int negIndex = 1;

    vector<int> result(n, 0);

    for(int i = 0; i < n; i++){

        if(nums[i] >= 0){
            result[posIndex] = nums[i];
            posIndex += 2;
        }
        else{
            result[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return result;
}