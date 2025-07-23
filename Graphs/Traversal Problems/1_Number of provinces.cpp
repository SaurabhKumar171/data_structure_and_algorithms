#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Approach :  O(V^2) time complexity , O(V) space complexity
class Solution{
private:
    void bfs(int node, vector<int> adjList[], int vis[]){
        vis[node] = 1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int i = q.front();
            q.pop();

            for(auto adjNodes : adjList[i]){
                if(vis[adjNodes] != 1){
                    vis[adjNodes] = 1;
                    q.push(adjNodes);
                }
            }
        }
    }
public:
    int numProvinces(vector<vector<int>> adj) {
       int V = adj.size();

       vector<int> adjList[V];

       for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i != j && adj[i][j] == 1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
       }

       int vis[V] = {0};

       int cnt = 0;
       
       for(int i = 0; i < V; i++){
        if(vis[i] == 0){
            cnt++;
            bfs(i, adjList, vis);
        }
       }

       return cnt;
    }
};