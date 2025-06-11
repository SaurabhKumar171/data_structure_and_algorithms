
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach : O(n^2) time complexity, O(1) space complexity
class Solution
{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
       vector <int> ans;

       for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i; j >= 0; j--){
            if(arr[j] <= arr[i]) count++;
            else break;
        }
        ans.push_back(count);
       }

       return ans;
    }
};



// Optimal Approach : O(n) + o(n) time complexity, O(n) + o(n) space complexity
class Solution
{
    private:
        void prevGreaterElement(vector<int>& arr, int n, vector<int>& pgeArray){
            stack<int> st;

            for(int i = 0; i < n; i++){
                while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
                if(!st.empty()) pgeArray[i] = st.top();
                st.push(i);
            }
        }
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
       vector <int> ans(n);
       vector <int> pgeArray(n, -1);
       
       prevGreaterElement(arr, n, pgeArray);

       for(int i = 0; i < n; i++){
        if(pgeArray[i] == -1) ans[i] = i + 1;
        else ans[i] = i - pgeArray[i];
       }

       return ans;
    }
};
