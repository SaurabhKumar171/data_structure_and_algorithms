
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

//Approach :  O() time complexity, O(1) space complexity[width at any level]
 class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // if both are null
            if(p == NULL && q == NULL) return true;
            // if only one is null
            if(p == NULL || q == NULL) return false;
    
            if(p->data != q->data) return false;
    
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };

