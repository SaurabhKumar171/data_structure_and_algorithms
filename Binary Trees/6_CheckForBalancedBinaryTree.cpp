
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

//Brute Approach :  O(n^2) time complexity, O(n) space complexity[recursion stack]
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

//Brute Approach :  O(n) time complexity, O(h) space complexity[height of the tree - recursion stack]
class Solution {
    private:
     int dfsHeight(TreeNode* node) {
         if (node == NULL) return 0;
         int left = dfsHeight(node->left);
         if(left == -1) return -1;
 
         int right = dfsHeight(node->right);
         if(right == -1) return -1;
 
         if(abs(left - right) > 1) return -1;
 
         return max(left, right) + 1;
     }
 
    public:
     bool isBalanced(TreeNode* root) {
         return dfsHeight(root) != -1;
     }
 };