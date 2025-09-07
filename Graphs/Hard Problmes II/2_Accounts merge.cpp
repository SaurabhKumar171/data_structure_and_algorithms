
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet {
   public:
    vector<int> rank, size, parent;

   public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUlitimateParent(int node) {
        if (node == parent[node]) return node;

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

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUlitimateParent(u);
        int ulp_v = findUlitimateParent(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
        int n = accounts.size();

        unordered_map<string, int> mp;
        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mp.find(mail) != mp.end()) {
                    ds.unionByRank(i, mp[mail]);
                } else {
                    mp[mail] = i;
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it: mp){
            string mail = it.first;
            int node = ds.findUlitimateParent(it.second);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }

};