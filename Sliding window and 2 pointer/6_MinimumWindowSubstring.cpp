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