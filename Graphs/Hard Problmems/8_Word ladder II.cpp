#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Time Complexity:O(L * N * 26 * M), where L is the length of the wordList, N is the length of beginWord, and M is the length of the words in wordList
// Space Complexity:O(L), where L is the length of the wordList
class Solution{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord});
        unordered_set<string> toErase;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                vector<string> seq = q.front();

                string word = seq.back();
                q.pop();

                if(word == endWord){
                    if(ans.empty()){
                        ans.push_back(seq);
                    }
                    else if(ans.back().size() == seq.size()){
                        ans.push_back(seq);
                    }
                }

                for(int pos = 0; pos < word.length(); pos++){
                    char original = word[pos];

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[pos] = ch;

                        if(st.find(word) != st.end()){
                            seq.push_back(word);
                            q.push(seq);
                            toErase.insert(word);
                            seq.pop_back();
                        }
                    }

                    word[pos] = original;
                }
            }

            for(auto it: toErase) st.erase(it);
            toErase.clear();

            if(!ans.empty()) break;
        }

        return ans;
    }
};