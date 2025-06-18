
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
        int solve(TreeNode* node, int& maxSum){
            if(node == nullptr) return 0;
    
            int leftSum = max(0, solve(node->left, maxSum));
            int rightSum = max(0, solve(node->right, maxSum));
    
            maxSum = max(maxSum, rightSum + leftSum + node->data);
    
            return max(leftSum, rightSum) + node->data;
        }
    public:
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            solve(root, maxSum);
            return maxSum;
        }
    };	