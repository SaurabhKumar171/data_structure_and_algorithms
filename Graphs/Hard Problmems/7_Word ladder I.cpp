#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// Form 1
//Approach : O(N * M * 26), time complexity ,  O(N) space complexity
class Solution{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == targetWord) return level;

            // N * wordlength * 26 * log N
            for(int i = 0; i < word.size(); i++){
                char originalWord = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }

                word[i] = originalWord;
            }
        }

        return 0;
    }
};