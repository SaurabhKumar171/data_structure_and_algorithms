#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute force Approach: O(n^2) time complexity , O(n) space complexity
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLen = 0, n = s.size();
    
            for(int i = 0; i < s.size(); i++){
    
               vector<int> hash(256, 0);
    
               for(int j = i; j < n; j++){
                    if(hash[s[j]] == 1) break;
    
                    hash[s[j]] = 1;
                    maxLen = max(maxLen, j - i + 1);
               }
            }
    
            return maxLen;
        }
    };


// Optimized Approach: O(n) time complexity , O(n) space complexity
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> hash;
    
            int maxLen = 0, n = s.size();
            int r = 0, l = 0;
    
            while(r < n){
                if(hash.find(s[r]) != hash.end()){
                    l = max(l, hash[s[r]] + 1);
                }
                    
                hash[s[r]] = r;
                
                maxLen = max(maxLen, r - l + 1);     
                r++;     
            }
    
            return maxLen;
        }
    };