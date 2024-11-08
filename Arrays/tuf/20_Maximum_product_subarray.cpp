#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = i; j < n; j++){
                prod = prod*nums[j];
                maxProduct = max(maxProduct, prod);
            }
        }

        return maxProduct;
    }
};

// Better Approach
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        int n = nums.size();

        vector<int> prefixMultplication; 
        int prod = 1;
        for(int i = 0; i < n; i++){  // Line 9: Suggest renaming 'prod' to 'currentProduct' for clarity.
           prod *= nums[i];
           prefixMultplication.push_back(prod);

           if(nums[i] == 0) prod = 1;  // Line 12: Suggest adding a comment to explain why the product is reset when encountering zero.
        }

        vector<int> suffixMultplication; 
        prod = 1;
        for(int i = n-1; i >= 0; i--){
           prod *= nums[i];
           suffixMultplication.push_back(prod);

           if(nums[i] == 0) prod = 1;  // Line 18: Suggest adding a comment to explain why the product is reset when encountering zero.
        }

        for(int i = 0; i < n; i++){
            ans = max(ans, max(prefixMultplication[i], suffixMultplication[i]));
        }

        return ans;
    }
};

// Optimal Approach
class Solution3 {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        int n = nums.size();

        int suffixMultiplication = 1;
        int prefixMultiplication = 1;

        for(int i = 0; i < n; i++){
           suffixMultiplication *= nums[i];
           ans = max(ans , suffixMultiplication);

            prefixMultiplication *= nums[n-1-i];
           ans = max(ans , prefixMultiplication);

            if(nums[i] == 0){
                suffixMultiplication = 1;
            }

            if(nums[n-1-i] == 0){
                prefixMultiplication = 1;
            }

        }

        return ans;
    }
};
