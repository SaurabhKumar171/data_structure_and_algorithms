// Brute force Approach
class Solution1 {
public:
    vector<int> unionArrayBruteForceApproach(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> uniqueElements; // Line 5: Suggest renaming for clarity
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){
            uniqueElements.insert(nums1[i]); // Line 8: Consider extracting this loop into a private function for modularization
        }

        for(int i = 0; i < nums2.size(); i++){
            uniqueElements.insert(nums2[i]); // Line 12: Consider extracting this loop into a private function for modularization
        }

        for(int i : uniqueElements){
            ans.push_back(i);
        }

        return ans;
    }
};




// Optimal Approach
class Solution2 {
public:
    vector<int> unionArrayOptimalApproach(vector<int>& nums1, vector<int>& nums2) {
        
        // set<int> s;
        vector<int> ans;
        int i = 0;
        int j = 0;

        int n = nums1.size();
        int m = nums2.size();

        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                if(ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }
                
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                if(ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }               
               
                i++;
            }
            else if(nums1[i] > nums2[j]){
                if(ans.empty() || ans.back() != nums2[j]){
                    ans.push_back(nums2[j]);
                }                  
                
                j++;
            }
        }

        while(i < n){
            if(ans.empty() || ans[ans.size()-1] != nums1[i]){
                ans.push_back(nums1[i]);
            }
                
            i++;
        }

        while(j < m){
            if(ans.empty() || ans[ans.size()-1] != nums2[j]){
                ans.push_back(nums2[j]);
            }
                
            j++;
        }

        return ans;
    }
};