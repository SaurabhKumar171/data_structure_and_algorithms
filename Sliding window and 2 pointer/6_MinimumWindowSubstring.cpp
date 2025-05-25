// Brute Force Approach: O(n^2) time complexity, O(k) space complexity
class Solution {
    public:
        string minWindow(string s, string t) {
             
            int minLen = INT_MAX, n = s.size();
            string ans = "";
    
            for(int i = 0; i < n; i++){
                unordered_map<char, int> hash;
    
                for(int j = 0; j < t.size(); j++){
                    hash[t[j]]++;
                }
    
                int cnt = 0;
    
                for(int j = i; j < n; j++){
                    
                    if(hash[s[j]] > 0) cnt++;
                    
                    hash[s[j]]--;
    
                    if(cnt == t.size() && minLen > j - i + 1){
                        ans = s.substr(i, j - i + 1);
                        minLen = min(minLen, j - i + 1);
                    }
                }
            }
    
            return ans;        
        }
    };



// Optimal Approach: O(n + m) time complexity , O(256) space complexity
class Solution {
    public:
        string minWindow(string s, string t) {
    
            int sIndex = -1;
            int hash[256] = {0};
    
            for(char c : t){
                hash[c]++;
            }
    
            int l = 0, r = 0;
            int minLen = INT_MAX, n = s.size();
            string ans = "";
            int cnt = 0;
    
    
            while(r < n){                
                if(hash[s[r]] > 0) cnt++;
                    
                hash[s[r]]--;
    
                while(cnt == t.size()){
                    if(minLen > r - l + 1){
                        sIndex = l;
                        minLen = r - l + 1;
                    }
    
                    hash[s[l]]++;
    
                    if(hash[s[l]] > 0) cnt--;
    
                    l++;
                }
    
                r++;
            }
    
            return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
        }
    };