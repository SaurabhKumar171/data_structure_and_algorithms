
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

//Approach :  O(n + n + h) ~ o(n) time complexity, O(n) space complexity[recursion stack]
 class Solution {
    private:
     bool isLeaf(TreeNode* root) { return !root->left && !root->right; }
 
     void leftBoundary(TreeNode* root, vector<int>& res) {
         TreeNode* curr = root->left;
         while (curr != nullptr) {
             if (!isLeaf(curr)) res.push_back(curr->data);
 
             if (curr->left == nullptr)
                 curr = curr->right;
             else
                 curr = curr->left;
         }
     }
 
     void rightBoundary(TreeNode* root, vector<int>& res) {
         TreeNode* curr = root->right;
         vector<int> temp;
         while (curr != nullptr) {
             if (!isLeaf(curr)) temp.push_back(curr->data);
 
             if (curr->right == nullptr)
                 curr = curr->left;
             else
                 curr = curr->right;
         }
 
         for (int i = temp.size() - 1; i >= 0; i--) {
             res.push_back(temp[i]);
         }
     }
 
     void addLeaves(TreeNode* root, vector<int>& res) {
         if (isLeaf(root)) {
             res.push_back(root->data);
             return;
         }
 
         if(root->left) addLeaves(root->left, res);
         if(root->right) addLeaves(root->right, res);
     }
 
    public:
     vector<int> boundary(TreeNode* root) {
         vector<int> res;
 
         if (!root) return res;
         if (!isLeaf(root)) res.push_back(root->data);
 
         leftBoundary(root, res);
         addLeaves(root, res);
         rightBoundary(root, res);
 
         return res;
     }
 };