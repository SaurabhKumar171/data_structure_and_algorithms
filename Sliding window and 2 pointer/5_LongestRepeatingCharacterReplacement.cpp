#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute force Approach: O(n^2) time complexity , O(256) space complexity

class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n = s.size();
            int maxLen = 0;
    
            for(int i = 0; i < n; i++){
                
                vector<int> hash(26, 0);
                int maxFreq = 0;
    
                for(int j = i; j < n; j++){
                    hash[s[j] - 'A']++;
    
                    maxFreq = max(maxFreq, hash[s[j] - 'A']);
                    int changes = (j - i + 1) - maxFreq;
                    
                    if(changes > k) break;
    
                    maxLen = max(maxLen, j - i + 1);
                }
    
            }
    
            return maxLen;        
        }
    };



    // Better Approach: O(n * 26) time complexity , O(26) space complexity
    class Solution {
        public:
            int characterReplacement(string s, int k) {
                int n = s.size();
                int l = 0, r = 0, maxFreq = 0, maxLen = 0;
                vector<int> hash(26, 0);
        
        
                while(r < n){
                    hash[s[r] - 'A']++;
        
                    maxFreq = max(maxFreq, hash[s[r] - 'A']);
        
                    while((r - l + 1) - maxFreq > k){
                        hash[s[l] - 'A']--;
        
                        maxFreq = 0;
                        for(int i = 0; i < 26; i++){
                            maxFreq = max(maxFreq, hash[i]);
                        }
        
                        l++;
                    }
        
                    maxLen = max(maxLen, r - l + 1);
                    r++;
                }
        
                return maxLen;        
            }
        };