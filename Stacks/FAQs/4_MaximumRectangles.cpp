
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach : O(m*n) + o(m*n) time complexity, O(n*m) + O(m) + O(m) space complexity
class Solution
{
private:
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

    void pse(vector<int> &arr, vector<int> &pseArray) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) pseArray[i] = st.top();
            st.push(i);
        }
    }
    
    int maxAreaHistogram(vector<int>& heights){
        int n = heights.size();
        int ans = 0;

        vector<int> nseArray(n, n), pseArray(n, -1);
        nse(heights, nseArray);
        pse(heights, pseArray);

        for(int i = 0; i < n; i++){
            ans = max(ans, ((nseArray[i] - pseArray[i] - 1)* heights[i]));
        }

        return ans;  
    }
public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
       
       int n = matrix.size(), m = matrix[0].size();
       vector<vector<int>> prefixSumMatrix(n, vector<int>(m, 0));

       for(int i = 0; i < m; i++){
        
        int sum = 0;

        for(int j = 0; j < n; j++){
            sum += matrix[j][i];
            
            if(matrix[j][i] == 0) sum = 0;
            
            prefixSumMatrix[j][i] = sum;
        }
       }

        int ans = 0;
       for(int i = 0; i < n; i++){
        ans = max(ans, maxAreaHistogram(prefixSumMatrix[i]));
       }

       return ans;
    }
};