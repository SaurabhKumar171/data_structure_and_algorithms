#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Approach :  O(n) time complexity - As we're traversing n no. of nodes (all in tree), O(n) space complexity[recursion stack]
class Solution {
    private:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                            int preStart, int preEnd, int inStart, int inEnd,
                            unordered_map<int, int>& mpp) {
            if (preStart > preEnd || inStart > inEnd) return nullptr;
    
            TreeNode* root = new TreeNode(preorder[preStart]);
            int inRootIndex = mpp[root->val];
    
            int numsLeft = inRootIndex - inStart;
    
            root->left = buildTree(preorder, inorder, preStart + 1, preStart + numsLeft, inStart,
                      inRootIndex - 1, mpp);
    
            root->right = buildTree(preorder, inorder, preStart + numsLeft + 1, preEnd,
                      inRootIndex + 1, inEnd, mpp);
    
            return root;
        }
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> mpp;
    
            for (int i = 0; i < inorder.size(); i++) {
                mpp[inorder[i]] = i;
            }
    
            return buildTree(preorder, inorder, 0, preorder.size() - 1, 0,
                             inorder.size() - 1, mpp);        
        }
    };