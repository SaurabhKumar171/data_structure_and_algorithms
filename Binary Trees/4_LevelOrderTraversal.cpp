
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


//Approach :  O(n) time complexity, O(w) space complexity[width at any level]
 class Solution {
    public:
        vector<vector<int> > levelOrder(TreeNode* root) {
            vector<vector<int> > ans;
            if(root == NULL) return ans;
    
            queue<TreeNode*> q;
            q.push(root);
    
            while(!q.empty()){
                int size = q.size();
                vector<int> level;
    
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();
    
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
    
                    level.push_back(node->data);
                }
    
                ans.push_back(level);
            }
    
            return ans;
        }
    };