#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// Brute Force Approach : O(n) + O(n) + O(n) time complexity, O(2n) + O(2n) space complexity

class Solution {
    private:
        vector<int> findNSE(vector<int> &arr) {
            int n = arr.size();
            
            vector<int> ans(n);
            
            stack<int> st;
        
            for(int i = n - 1; i >= 0; i--) {
                
    
                int currEle = arr[i];
            
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                
                ans[i] = !st.empty() ? st.top() : n;
                
                st.push(i);
            }
            
            return ans;
        }
        
        vector<int> findPSE(vector<int> &arr) {
            int n = arr.size();
            
            vector<int> ans(n);
            stack<int> st;
            
            for(int i=0; i < n; i++) {            
                int currEle = arr[i];
                
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                
                ans[i] = !st.empty() ? st.top() : -1;
                st.push(i);
            }        
            return ans;
        }
    
    public:
        int largestRectangleArea(vector<int>& heights) {
         int n = heights.size(), ans = INT_MIN;
         vector<int> nse = findNSE(heights);
         vector<int> pse = findPSE(heights);
    
         for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
         }
    
         return ans;     
        }
    };