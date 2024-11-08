#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;

        int cnt = 0;
        int XOR = 0;

        for(int i = 0; i < n; i++){

            XOR ^= nums[i];
            int diff = XOR^k;

            if(map.find(diff) != map.end()){
                cnt += map[diff];
            }
            
            map[XOR]++;
        }

        return cnt;
    }
};