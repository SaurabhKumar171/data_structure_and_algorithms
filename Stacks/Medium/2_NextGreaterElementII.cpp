// Brute force Approach: O(n^2) time complexity, O(1) space complexity
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& arr) {
            int n = arr.size();
            vector<int> ans(n, -1);
            
            for(int i = 0; i < n; i++){
    
                int j = (i + 1)%n;
    
                while(j != i){
                    if(arr[j] > arr[i]){
                        ans[i] = arr[j];
                        break;
                    }
    
                    j = (j + 1)%n;
                }
            }
    
            return ans;        
        }
    };



  
    // Optimized Approach: O(n) time complexity, O(n) space complexity
    class Solution {
        public:
            vector<int> nextGreaterElements(vector<int>& arr) {
                int n = arr.size();
                vector<int> ans(n, -1);
        
                stack<int> prevSt;
                for(int i = n - 1; i >= 0; i--){
                    prevSt.push(arr[i]);
                }
        
                stack<int> newSt;
                
                for(int i = n - 1; i >= 0; i--){
        
                    while(!newSt.empty() && newSt.top() <= arr[i]){
                        newSt.pop();
                    }
                    while(!prevSt.empty() && prevSt.top() <= arr[i]){
                        prevSt.pop();
                    }
                    if(!newSt.empty()){
                        ans[i] = newSt.top();
                    }
                    else if(!prevSt.empty()){
                        ans[i] = prevSt.top();
                    }
                    
                    newSt.push(arr[i]);
                }
        
                return ans;        
            }
        };