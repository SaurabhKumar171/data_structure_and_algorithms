#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach : O(n^2) time complexity, O(1) space complexity
class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            
            int n = nums.size();
            long long totalSum = 0;
    
            for(int i = 0; i < n; i++){
    
                int maximum = nums[i]; 
                int minimum = nums[i]; 
    
                for(int j = i; j < n; j++){
                    maximum = max(maximum, nums[j]);
                    minimum = min(minimum, nums[j]);
    
                    totalSum += (maximum - minimum)*1LL;
                }
            }
    
            return totalSum;
        }
    };



// Optimal Approach : O(n) time complexity, O(n) space complexity
class Solution {
    private:
        void pse(vector<int> &arr, vector<int> &pseArray) {
            stack<int> st;
            for (int i = 0; i < arr.size(); i++) {
                while (!st.empty() && arr[i] < arr[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) pseArray[i] = st.top();
                st.push(i);
            }
        }
    
        void nse(vector<int> &arr, vector<int> &nseArray) {
            stack<int> st;
            for (int i = arr.size() - 1; i >= 0; i--) {
                while (!st.empty() && arr[i] <= arr[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) nseArray[i] = st.top();
                st.push(i);
            }
        }
    
        long long sumSubarrayMins(vector<int> &arr) {
            int n = arr.size();
            int mod = 1e9 + 7;
            long long ans = 0;
    
            vector<int> pseArray(n, -1);
            vector<int> nseArray(n, n);
    
            pse(arr, pseArray);
            nse(arr, nseArray);
    
            for (int i = 0; i < n; i++) {
                long long left = i - pseArray[i];
                long long right = nseArray[i] - i;
                long long freq = left*right*1LL;
                long long val = (freq*arr[i]*1LL);
                ans += val;
            }
    
            return ans;
        }
    
        void pge(vector<int> &arr, vector<int> &pgeArray) {
            stack<int> st;
            for (int i = 0; i < arr.size(); i++) {
                while (!st.empty() && arr[i] > arr[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) pgeArray[i] = st.top();
                st.push(i);
            }
        }
    
        void nge(vector<int> &arr, vector<int> &ngeArray) {
            stack<int> st;
            for (int i = arr.size() - 1; i >= 0; i--) {
                while (!st.empty() && arr[i] >= arr[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) ngeArray[i] = st.top();
                st.push(i);
            }
        }
    
        long long sumSubarrayMaxs(vector<int> &arr) {
            int n = arr.size();
            int mod = 1e9 + 7;
            long long ans = 0;
    
            vector<int> pgeArray(n, -1);
            vector<int> ngeArray(n, n);
    
            pge(arr, pgeArray);
            nge(arr, ngeArray);
    
            for (int i = 0; i < n; i++) {
                long long left = i - pgeArray[i];
                long long right = ngeArray[i] - i;
                long long freq = left*right*1LL;
                long long val = (freq*arr[i]*1LL);
                ans += val;
            }
    
            return ans;
        }
    public:
        long long subArrayRanges(vector<int>& arr) {
            return ( sumSubarrayMaxs(arr) - 
                     sumSubarrayMins(arr) );
        }
    };