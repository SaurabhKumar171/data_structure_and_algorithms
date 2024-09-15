// Brute force
class Solution1 {
public:
    void moveZeroesBruteForce(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0) temp.push_back(nums[i]);
        }

        fill(nums.begin(), nums.end(), 0);

        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
        }
    }
};

// Optimal approach
class Solution2 {
public:
    void moveZeroesOptimalApproach(vector<int>& nums) {

        int n = nums.size();
        int i = -1;
        int j = -1;

        for(int k = 0; k < n; k++){
            if(nums[k] == 0){ 
                i = k;
                break;
            }
        }

        if(i == -1) return;

        j = i + 1;

        while(i < n && j < n){
            if(nums[i] != 0) i++;
            if(nums[j] == 0) j++;
            else if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};