
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

 class Solution {
    private:
     int getHeight(TreeNode* node) {
         if (node == NULL) return 0;
         int left = getHeight(node->left);
         int right = getHeight(node->right);
         return max(left, right) + 1;
     }
 
    public:
     bool isBalanced(TreeNode* root) {
         if (root == NULL) return true;
 
         int leftHeight = getHeight(root->left);
         int rightHeight = getHeight(root->right);
 
         if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) &&
             isBalanced(root->right))
             return true;
         
         return false;
     }
 };