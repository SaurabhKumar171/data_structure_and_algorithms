#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force approach
class Solution1 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        int repeatingNumber = -1;
        int missingNumber = -1;

        for(int i = 1; i <= n; i++){ 
            
            int cnt = 0;

            for(int j = 0; j < n; j++){ 

                if(i == nums[j]){
                    cnt++;
                }

            }

            if(cnt == 2){
                repeatingNumber = i;
            }

            if(cnt == 0){
                missingNumber = i;
            }

            if(repeatingNumber != -1 && missingNumber != -1){
                break;
            }

        }

        return {repeatingNumber, missingNumber};
    }
};


// Better approach
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        int repeatingNumber = -1;
        int missingNumber = -1;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for(int i = 1; i <= n; i++){

           if(mp.find(i) == mp.end()){
            missingNumber = i;
           }
           else if(mp[i] >= 2){
            repeatingNumber = i;
           }

            if (repeatingNumber != -1 && missingNumber != -1)
                break;        
        }

        return {repeatingNumber, missingNumber};
    }
};