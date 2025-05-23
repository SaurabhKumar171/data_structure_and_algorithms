#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Problem: https://leetcode.com/problems/fruit-into-baskets/



// Brute force Approach: O(n^2) time complexity , O(1) space complexity
class Solution{
    public:
      int totalFruits(vector<int>& fruits){
          int n = fruits.size();
          int maxCnt = 0;
  
          for(int i = 0; i < n; i++){
              int t1 = -1, t2 = -1;
  
              for(int j = i; j < n; j++){
                  if(t1 == -1 && t2 != fruits[j]){
                      t1 = fruits[j];
                  }
                  else if(t2 == -1 && t1 != fruits[j]){
                      t2 = fruits[j];
                  }
  
                  if(t1 != fruits[j] && t2 != fruits[j]) break;
  
                  maxCnt = max(maxCnt, j - i + 1);        
              }    
          }
  
          return maxCnt;    
      }
  };


// Better Approach: O(n + n) time complexity , O(3) space complexity
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
            int maxCnt = 0;
    
            int l = 0, r = 0;
            unordered_map<int, int> hash;
    
            while(r < n){
                hash[fruits[r]]++;
    
                if(hash.size() > 2){
                    while(hash.size() > 2){
                        hash[fruits[l]]--;
    
                        if(hash[fruits[l]] == 0){
                            hash.erase(fruits[l]);
                        }
                        
                        l++;
                    }
                }
    
                if(hash.size() <= 2) maxCnt = max(maxCnt, r - l + 1);        
    
                r++;
            }
    
            return maxCnt;
        }
    };


// Optimal Approach: O(n) time complexity , O(3) space complexity
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
            int maxCnt = 0;
    
            int l = 0, r = 0, k = 2;
            unordered_map<int, int> hash;
    
            while(r < n){
                hash[fruits[r]]++;
    
                if(hash.size() > k){
                    if(hash.size() > k){
                        hash[fruits[l]]--;
    
                        if(hash[fruits[l]] == 0){
                            hash.erase(fruits[l]);
                        }
                        
                        l++;
                    }
                }
    
                if(hash.size() <= k) maxCnt = max(maxCnt, r - l + 1);        
    
                r++;
            }
    
            return maxCnt;
        }
    };