#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Better Approach
class Solution {
public: // 1 2 3 4 100 200
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        int longestSequence = 1;

        sort(nums.begin(), nums.end());

        if(n <= 1) return n;

        int cnt = 0;
        int prevElement = INT_MIN; 

        for(int i = 0; i < n; i++){

            if(nums[i] - 1 == prevElement){
                cnt++;
                prevElement = nums[i];
            }
            else if (nums[i] != prevElement) {
                prevElement = nums[i];
                cnt = 1;
            }
            longestSequence = max(longestSequence, cnt);
        }

        return longestSequence;
    }
};


// Optimal Approach
class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longestSequence = 0;

        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto i: st){

            if(st.find(i - 1) == st.end()){

                int cnt = 1;
                int x = i;
                
                while(st.find(x + 1) != st.end()){
                    cnt++;
                    x += 1;
                }

                longestSequence = max(longestSequence, cnt);

            }
        }

        return longestSequence;
    }
};