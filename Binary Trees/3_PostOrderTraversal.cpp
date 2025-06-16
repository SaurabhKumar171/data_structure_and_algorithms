
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
            func(ans, root->right);

            ans.push_back(root->data);

        }
	public:
		vector<int> postorder(TreeNode* root){
	        vector<int> ans;
            func(ans, root);

            return ans;			
        }
};

// Iterative Approach :  O(n) time complexity, O(n) space complexity
class Solution{
	public:
		vector<int> postorder(TreeNode* root){
            vector<int> list;
            stack<TreeNode*> st;
            st.push(root);

            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                list.push_back(node->data);
                
                if(node->left != NULL) st.push(node->left);
                if(node->right != NULL) st.push(node->right);
            }

            reverse(list.begin(), list.end());
          
           return list;		
        }
};
