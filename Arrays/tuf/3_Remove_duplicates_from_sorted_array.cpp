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

// Optimal approach
class Solution2 {
public:
    int removeDuplicatesOptimalApproach(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        // int j = 1;


        for (int j = 1; j < nums.size(); j++) {
            /*If current element is different 
            from the previous unique element*/
            if (nums[i] != nums[j]) {
                /* Move to the next position in 
                the vector for the unique element*/
                i++;
                /* Update the current position 
                with the unique element*/
                swap(nums[i], nums[j]);
            }
        }

        int k = i + 1;

        return k;
    }
};