// Brute Force Approach: O(n^2) time complexity, O(3) space complexity

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
    
            int stringCount = 0;
    
            for(int i = 0; i < n; i++){
                
                vector<int> hash(3, 0);
    
                for(int j = i; j < n; j++){
                    hash[s[j] -'a'] = 1;
    
                    if(hash[0] + hash[1] + hash[2] == 3){
                        stringCount++;
                    }
                }
            }
    
             return stringCount; 
        }
    };



// Optimal Approach: O(n) time complexity, O(3) space complexity
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
    
            int stringCount = 0;
            int lastSeen[3] = {-1, -1, -1};
    
            for(int i = 0; i < n; i++){
                
                lastSeen[s[i] - 'a'] = i;
    
                if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                    stringCount += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
                }
            }
    
            return stringCount; 
        }
    };