
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

// BFS approach : O(NlogN) time complexity, O(N) space complexity
class Solution{
    public:
    vector<int> topView(TreeNode *root){
        vector<int> ans;
        if(!root) return ans;

        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            auto [node, line] = q.front();

            if(node->left) q.push({node->left, line - 1});
            if(node->right) q.push({node->right, line + 1});

            if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
            q.pop();
        }

        for(auto [line, val]: mpp){
            ans.push_back(val);
        }

        return ans;
    }
};