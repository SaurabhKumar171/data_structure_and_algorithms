
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

// Recursive Approach :  O(n) time complexity, O(n) space complexity
 class Solution{
    private:
        void func(TreeNode* node, vector<int>& list){
            if(node == NULL) return;

            list.push_back(node->data);
            func(node->left, list);
            func(node->right, list);
        }
	public:
		vector<int> preorder(TreeNode* root){
	       TreeNode* node = root;
           vector<int> list;
           func(node, list);
           return list;
		}
};


// Iterative Approach :  O(n) time complexity, O(n) space complexity
 class Solution{      
	public:
		vector<int> preorder(TreeNode* root){

            vector<int> list;
            stack<TreeNode*> st;
            st.push(root);

            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                list.push_back(node->data);

                if(node->right != NULL) st.push(node->right);
                if(node->left != NULL) st.push(node->left);
            }
          
           return list;
		}
};