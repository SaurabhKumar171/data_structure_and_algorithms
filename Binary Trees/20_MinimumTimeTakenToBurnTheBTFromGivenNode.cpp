#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 class Solution {
    private:
     TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp , int start) {
         queue<TreeNode*> q;
         q.push(root);
         TreeNode* res = new TreeNode(-1);
 
         while (!q.empty()) {
             TreeNode* node = q.front();
             q.pop();
 
             if (node->val == start) res = node;
             if (node->left != nullptr) {
                 mpp[node->left] = node;
                 q.push(node->left);
             }
             if (node->right != nullptr) {
                 mpp[node->right] = node;
                 q.push(node->right);
             }
         }
 
         return res;
     }
 
     int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target){
         queue<TreeNode*> q;
         q.push(target);
 
         unordered_map<TreeNode*, int> vis;
         vis[target] = 1;
         int maxi = 0;
 
         while(!q.empty()){
             int size = q.size();
             int fl = 0;
 
             for(int i = 0; i < size; i++){
                 TreeNode* node = q.front();
                 q.pop();
 
                 if(node->left != nullptr && vis.find(node->left) == vis.end()){
                     fl = 1;
                     vis[node->left] = 1;
                     q.push(node->left);
                 }
 
                 if(node->right != nullptr && vis.find(node->right) == vis.end()){
                     fl = 1;
                     vis[node->right] = 1;
                     q.push(node->right);
                 }
 
                 if(mpp.find(node) != mpp.end() && vis.find(mpp[node]) == vis.end()){
                     fl = 1;
                     vis[mpp[node]] = 1;
                     q.push(mpp[node]);
                 }
             }
 
             if(fl == 1) maxi++;
         }
 
         return maxi;
     }
 
    public:
     int timeToBurnTree(TreeNode* root, int start) {
         // your code goes here
         unordered_map<TreeNode*, TreeNode*> mpp;
         TreeNode* target = bfsToMapParents(root, mpp, start);
 
         int maxi = findMaxDistance(mpp, target);
         return maxi;
     }
 };