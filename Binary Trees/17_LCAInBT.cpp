
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
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == nullptr || root == p || root == q) return root;
    
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
            if(left == nullptr) return right;
            else if(right == nullptr) return left;
            else return root;
        }
    };