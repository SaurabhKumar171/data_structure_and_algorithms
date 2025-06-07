#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Optimal Approach :  O(n) time complexity, O(n) space complexity
class Solution {
    public:
      vector<int> leftSmaller(vector<int> arr) {
          int n = arr.size();
          vector<int> store(n, -1);
          stack<int> st;
  
         for(int i = 0; i < n; i++){
          while(!st.empty() && arr[i] <= st.top()) st.pop();
  
          if(!st.empty()) store[i] = st.top();
  
          st.push(arr[i]);
         }
  
         return store;        
      }
  };
  