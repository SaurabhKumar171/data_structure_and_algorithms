
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach : O(n^2) time complexity, O(n) space complexity
class Solution {
    public:
      int celebrity(vector<vector<int> >& M) {
          int n = M.size();
          
          vector<int> iknow(n , 0);
          vector<int> knowMe(n , 0);
  
          for(int i = 0; i < n; i++){
              for(int j = 0; j < n; j++){
                  if(i != j && M[i][j] == 1){
                      knowMe[j]++;
                      iknow[i]++;
                  } 
              }
          }
  
          for(int i = 0; i < n; i++){
              if(knowMe[i] == n - 1 && iknow[i] == 0) return i;
          }
          
          return -1; 
      }
  };


// Brute Force Approach : O(n) time complexity, O(1) space complexity
  class Solution
{
public:
    int celebrity(vector<vector<int>> &M){  
        int n = M.size();
        
        int top = 0, bottom = n - 1;

       while(top < bottom){
        if(M[top][bottom] == 1) top++;
        else if(M[bottom][top] == 1) bottom--;
        else{
            top++;
            bottom--;
        }
       }

       if(top > bottom) return -1;

        for(int i = 0; i < n; i++){
            if(i == top) continue;

            if(M[top][i] == 1 || M[i][top] == 0) return -1;
        }

        return top;
    }
};
