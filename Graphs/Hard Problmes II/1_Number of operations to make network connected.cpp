
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Time Complexity: O(E*4α) (where E is the number of edges in the graph and V is the number of nodes in the graph)
// O(Eα(V)) is for union and find operations of disjoint set data structure where α is the inverse Ackermann function which is very slow growing function and for all practical purposes, it

// Space Complexity: O(N) due to the rank, size, and parent vectors in the DisjointSet class. 

class DisjointSet {
private:
    vector<int> rank, size, parent;
public:
    DisjointSet(int n) {
     parent.resize(n + 1);
     rank.resize(n + 1, 0);
     size.resize(n + 1, 1);

     for(int i = 0; i <= n; i++){
        parent[i] = i;
     }
    }

    int findUlitimateParent(int node){
        if(node == parent[node]) return node;

        // Backtracking for path compression
        parent[node] = findUlitimateParent(parent[node]);
        return parent[node];
    }

    bool find(int u, int v) {
        return findUlitimateParent(u) == findUlitimateParent(v);
    }

    void unionByRank(int u, int v) {
     int ulp_u = findUlitimateParent(u);
     int ulp_v = findUlitimateParent(v);

     if(ulp_u == ulp_v) return;


     if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
     }
     else if(rank[ulp_v] < rank[ulp_u]){
        parent[ulp_v] = ulp_u;
     }
     else{
        parent[ulp_u] = ulp_v;
        rank[ulp_u]++;
     }
    }

    void unionBySize(int u, int v) {
     int ulp_u = findUlitimateParent(u);
     int ulp_v = findUlitimateParent(v);

     if(ulp_u == ulp_v) return;


     if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
     }
     else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
     }       
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int totalConnections = connections.size();

        int usedCables = 0;

        for(int i = 0; i < totalConnections; i++){
            int u = connections[i][0], v = connections[i][1];
            if(ds.findUlitimateParent(u) != ds.findUlitimateParent(v)){
                usedCables++;
                ds.unionByRank(u, v);
            }
        }

        int remainingCables = totalConnections - usedCables;
        int connectedComputers = usedCables + 1;
        int remainingComputers = n - connectedComputers;

        if(remainingComputers <= remainingCables) return remainingComputers;

        return -1;
    }
};