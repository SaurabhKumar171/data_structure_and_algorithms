
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
        void func(vector<int>& ans, TreeNode* root){
            if(root == NULL){ 
                return;
            }

            func(ans, root->left);
            ans.push_back(root->data);
            func(ans, root->right);
        }
	public:
		vector<int> inorder(TreeNode* root){
	        vector<int> ans;
            func(ans, root);

            return ans;
		}
};


// Iterative Approach :  O(n) time complexity, O(n) space complexity
class Solution{
	public:
		vector<int> inorder(TreeNode* root){
	        stack<TreeNode*> st;
            vector<int> list;
            TreeNode* node = root;

            while(true){
                if(node != NULL){
                    st.push(node);
                    node = node->left;
                }
                else{
                    if(st.empty()) break;

                    node = st.top();
                    st.pop();

                    list.push_back(node->data);
                    node = node->right;
                }
            }


            return list;
		}
};