// Brute force approach
class Solution1 {
public:
    int removeDuplicatesBruteForce(vector<int>& nums) {
        
        set<int> s;

        for(int i : nums){
            s.insert(i);
        }

        // unique elements count
        int k = s.size();
        int j = 0;
        for(int i : s){
            nums[j++] = i; 
        }

        return k;
    }
};