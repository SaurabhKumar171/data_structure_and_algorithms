
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
        vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
            vector<vector<int> > ans;
    
            if(root == nullptr) return ans;
    
            queue<TreeNode*> q;
            q.push(root);
    
            bool leftToRight = true;
    
            while(!q.empty()){
                int size = q.size();
    
                vector<int> row(size);
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();
    
                    int index = leftToRight ? i : (size - 1 - i);
                    row[index] = node->data;
    
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
    
                leftToRight = !leftToRight;
                ans.push_back(row);
            }
    
            return ans;
        }
    };