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
class Solution2 {
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


// Optimal Approach - I
class Solution3 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        long long n = nums.size();

        long long s = 0, sn = 0;
        long long s2 = 0, s2n = 0;

        sn = (n*(n+1))/2;
        s2n = (n*(n+1)*((2*n)+1))/6;

        for(int i = 0; i < n; i++){

            s += nums[i];

            s2 += (long long)(nums[i])*(long long)(nums[i]); 
        }

        long long val1 = s - sn;
        long long val2 = (s2 - s2n)/val1;

        long long repeating = (val2 + val1)/2;
        long long missing = val2 - repeating;
 
        return {(int)repeating , (int)missing};
    }
};