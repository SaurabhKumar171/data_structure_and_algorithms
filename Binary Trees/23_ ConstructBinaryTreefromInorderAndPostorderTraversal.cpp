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
        TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder,
                            int postStart, int postEnd, int inStart, int inEnd,
                            unordered_map<int, int>& mpp) {
            if (postStart < postEnd || inStart > inEnd) return nullptr;
    
            TreeNode* root = new TreeNode(postorder[postStart]);
            int inRootIndex = mpp[root->val];
    
            int numsRight = inEnd - inRootIndex;
    
            root->right = buildTree(postorder, inorder, postStart - 1,
                                    postStart - numsRight, inRootIndex + 1, inEnd, mpp);
    
            root->left =
                buildTree(postorder, inorder, postStart - 1 - numsRight, postEnd,
                          inStart, inRootIndex - 1, mpp);
    
            return root;
        }
    
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> mpp;
    
            for (int i = 0; i < inorder.size(); i++) {
                mpp[inorder[i]] = i;
            }
    
            return buildTree(postorder, inorder, postorder.size() - 1, 0, 0,
                             inorder.size() - 1, mpp);        
        }
    };