#include <iostream>
#include <vector>
#include <set>
using namespace std;

// DFS Approach : O(V + E) time complexity , O(V) space complexity
class Solution
{
private:
    void dfs(int i, vector<int> adj[], vector<bool> &vis,
             stack<int> &st)
    {
        vis[i] = true;

        for (auto node : adj[i])
        {
            if (!vis[node])
                dfs(node, adj, vis, st);
        }

        st.push(i);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

// BFS Approach : O(V + E) time complexity , O(V) space complexity
class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {

        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                inDegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                inDegree[it]--;

                if (inDegree[it] == 0)
                    q.push(it);
            }

            ans.push_back(node);
        }

        return ans;
    }
};
