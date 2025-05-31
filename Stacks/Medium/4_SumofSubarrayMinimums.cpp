// Brute Force Approach : O(n^2) time complexity, O(1) space complexity
class Solution {
    public:
        int sumSubarrayMins(vector<int> &arr) {
            int n = arr.size();
            int totalSum = 0;
            int mod = 1e9 + 7;
    
            for(int i = 0; i < n; i++){
                int minVal = arr[i];
                for(int j = i; j < n; j++){
                    minVal = min(minVal, arr[j]);
                    totalSum = (totalSum + minVal) % mod;
                }
            }

    
            return totalSum;
        }
    };
    


// Optimized Approach : O(n + n + n) time complexity, O(n + n + n) space complexity
class Solution {
    private:
        vector<int> findNSE(vector<int> &arr) {
            int n = arr.size();
            vector<int> ans(n);
            
            stack<int> st;
    
            for(int i = n - 1; i >= 0; i--){
    
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
    
                ans[i] = !st.empty() ? st.top() : n;
    
                st.push(i);
            }
    
            return ans;
        }
    
        vector<int> findPSEE(vector<int> &arr) {
            int n = arr.size();
            vector<int> ans(n);
            
            stack<int> st;
    
            for(int i = 0; i < n; i++){
                
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
    
                ans[i] = !st.empty() ? st.top() : -1;
    
                st.push(i);
            }
            return ans;
        }
    
    public:
        int sumSubarrayMins(vector<int> &arr) {
            vector<int> nse = findNSE(arr);
            vector<int> psee = findPSEE(arr);
    
            int n = arr.size();
    
            int mod = 1e9 + 7;
    
            int sum = 0;
    
            for(int i = 0; i < n; i++){
                int left = i - psee[i];
                int right = nse[i] - i;
    
                long long freq = left*right*1LL;
    
                int val = (freq*arr[i]*1LL) % mod;
    
                sum = (sum + val) % mod;
            }
    
            return sum;
        }
    };
    