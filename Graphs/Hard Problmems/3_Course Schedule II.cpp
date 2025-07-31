#include <iostream>
#include <vector>
using namespace std;

//Approach : DFS - O(N + E) time complexity ,  O(N) space complexity
class Solution {
private:
    vector<int> topoSort(int V, vector<vector<int>> adj){
        
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++){
            for(auto it: adj[i]) inDegree[it]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto it: adj[node]){
                inDegree[it]--;

                if(inDegree[it] == 0) q.push(it);
            }

            ans.push_back(node);
        }

        return ans;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);

        // creating adjacency list
        for(int i = 0; i < prerequisites.size(); i++){
            adjLs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> topo = topoSort(numCourses, adjLs);

        if(topo.size() < numCourses) return {};
        reverse(topo.begin(), topo.end());

        return topo;        
    }
};