#include <iostream>
#include <vector>
using namespace std;


// Form 1
//Approach : BFS - O(N*L + K + E) time complexity ,  O(K + E) space complexity
class Solution {
private:
    string topoSort(int V, vector<vector<int>> adj){
        
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++){
            for(auto it: adj[i]) inDegree[it]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        string ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto it: adj[node]){
                inDegree[it]--;

                if(inDegree[it] == 0) q.push(it);
            }

            ans += (node + 'a');
        }

        return ans;
    }

public:
	string findOrder(string dict[], int N, int K) {
		vector<vector<int>> adjList(K);

        for(int i = 1; i < N; i++){
            string str1 = dict[i - 1];
            string str2 = dict[i];

            int p = 0, q = 0;

            while(p < str1.size() && q < str2.size() && str1[p] == str2[q]){
                p++;
                q++;
            }

            if(p < str1.size() && q < str2.size()) adjList[str1[p] - 'a'].push_back(str2[q] - 'a');
        }

        string topo = topoSort(K, adjList);

        return topo;
	}
};



// Form 2
//Approach : BFS - O(N*L + K + E) time complexity ,  O(26) space complexity
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int V = words.size();
        vector<int> adj[26];
        vector<bool> exists(26, false);
        for (int i=0; i<words.size(); i++) {
            for (char ch : words[i]) {
                exists[ch - 'a'] = true;
            }
        }
        for(int i=0; i<V-1; i++){
            string str1 = words[i];
            string str2 = words[i+1];
            int j=0;
            while(j<str1.size() && j<str2.size() && str1[j] == str2[j]){
                j++;
            }
            if(j!= str1.size() && j == str2.size()){
                return "";
            }
            
            if (j < str1.size() && j < str2.size()) {
                adj[str1[j] - 'a'].push_back(str2[j] - 'a');
            }
        }
        
        vector<int>indegree(26,0);
        for(int i=0; i<26; i++){
            for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0; i<26; i++){
            if(exists[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += node + 'a';
            for(int j=0; j<adj[node].size(); j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]] == 0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        for(int i=0; i<26; i++){
            if(indegree[i] != 0){
                return "";
            }
        }
        
        return ans;    
    
    }
};