
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
 class Solution{
    private:
        bool isLeaf(TreeNode* root){
            if(!root) return true;

            return root->left == nullptr && root->right == nullptr;
        }

        void allRootToLeafHelper(TreeNode* root, vector<int>& list, vector<vector<int>>& res){
            if(!root) return;
            
            list.push_back(root->data);


            if(isLeaf(root)){
                res.push_back(list);
            }
            else{
                allRootToLeafHelper(root->left, list, res);
                allRootToLeafHelper(root->right, list, res);
            }

            list.pop_back();
        }
	public:
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>> res;
            vector<int> list;

            allRootToLeafHelper(root, list, res);

            return res;
		}
};