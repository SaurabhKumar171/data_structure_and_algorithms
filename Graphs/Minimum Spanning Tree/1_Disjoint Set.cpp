
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(4*alpha) ~ O(1) for find and union operations, where alpha is the inverse Ackermann function
// Space Complexity: O(n) for storing parent, rank, and size arrays
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
