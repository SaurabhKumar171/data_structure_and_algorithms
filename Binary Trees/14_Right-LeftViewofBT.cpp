
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

class Solution {
    private:
        void leftViewHelper(queue<pair<TreeNode*, int>>& q, map<int, int>& mpp, int size){
                for (int i = 0; i < size; i++) {
                    pair<TreeNode*, int> p = q.front();
                    TreeNode* node = p.first;
                    int line = p.second;
                    
                    if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
                    q.pop();

                    if (node->left) q.push({node->left, line + 1});
                    if (node->right) q.push({node->right, line + 1});
                }
        }
        void rightViewHelper(queue<pair<TreeNode*, int>>& q, map<int, int>& mpp, int size){
                for (int i = 0; i < size; i++) {
                    auto [node, line] = q.front();
    
                    if (node->left) q.push({node->left, line + 1});
                    if (node->right) q.push({node->right, line + 1});
    
                    mpp[line] = node->data;
                    q.pop();
                }
        }
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> ans;
            if (!root) return ans;
    
            map<int, int> mpp;
            queue<pair<TreeNode*, int>> q;
    
            q.push({root, 0});
    
            while (!q.empty()) {
                int size = q.size();
                rightViewHelper(q, mpp, size);
            }
    
            for (auto [line, val] : mpp) {
                ans.push_back(val);
            }
    
            return ans;        
        }
    };