#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> prefixSumMap;

        prefixSumMap[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;
            
            //Acc. to rule kn + x; x is remainder if its -ve it can be paired with k - x 
            //as we can write kn - x (here rem is -ve (-x)) 
            //it'll be kn - x + k - k ; 
            //k(n - 1) + k - x
            //k-x is the nen remainder
            (rem < 0) ? (rem += k) : (rem); 

            if(prefixSumMap.find(rem) != prefixSumMap.end()){
                count += prefixSumMap[rem];
            }

            prefixSumMap[rem]++;            
        }

        return count;
    }
};