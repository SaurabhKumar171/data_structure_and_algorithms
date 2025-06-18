
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

//Approach :  O(n) time complexity, O(n) space complexity[recursion stack]

 class Solution {
    private:
     bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
         if (left == nullptr || right == nullptr) return left == right;
 
         if (left->data != right->data) return false;
 
         return isSymmetricHelp(left->left, right->right) &&
                isSymmetricHelp(left->right, right->left);
     }
 
    public:
     bool isSymmetric(TreeNode* root) {
         return root == nullptr || isSymmetricHelp(root->left, root->right);
     }
 };