#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute force Approach: O(n^2) time complexity , O(k) space complexity
class Solution {
    public:
        int kDistinctChar(string& s, int k) {
            int n = s.size();
            int maxCnt = 0;
    
            int l = 0, r = 0;
            unordered_map<char, int> hash;
    
            while(r < n){
                hash[s[r]]++;
    
                if(hash.size() > k){
                    if(hash.size() > k){
                        hash[s[l]]--;
    
                        if(hash[s[l]] == 0){
                            hash.erase(s[l]);
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



// Optimal Approach: O(n) time complexity , O(k) space complexity
class Solution {
    public:
        int kDistinctChar(string& s, int k) {
            int n = s.size();
            int maxCnt = 0;
    
            int l = 0, r = 0;
            unordered_map<char, int> hash;
    
            while(r < n){
                hash[s[r]]++;
    
                if(hash.size() > k){
                    if(hash.size() > k){
                        hash[s[l]]--;
    
                        if(hash[s[l]] == 0){
                            hash.erase(s[l]);
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

