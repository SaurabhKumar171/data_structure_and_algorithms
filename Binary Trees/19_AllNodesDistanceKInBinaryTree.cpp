
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*, TreeNode*> parentMap;
            queue<TreeNode*> q;
            q.push(root);
    
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
    
                if (node->left) {
                    parentMap[node->left] = node;
                    q.push(node->left);
                }
    
                if (node->right) {
                    parentMap[node->right] = node;
                    q.push(node->right);
                }
            }
    
            vector<int> result;
            unordered_set<TreeNode*> visited;
            q.push(target);
            visited.insert(target);
            int currentDistance = 0;
    
            while (!q.empty()) {
                if (currentDistance == k) {
                    while (!q.empty()) {
                        result.push_back(q.front()->val);
                        q.pop();
                    }
                    return result;
                }
    
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    if (node->left && visited.find(node->left) == visited.end()) {
                        q.push(node->left);
                        visited.insert(node->left);
                    }
                    if (node->right && visited.find(node->right) == visited.end()) {
                        q.push(node->right);
                        visited.insert(node->right);
                    }
    
                    if (parentMap.find(node) != parentMap.end() &&
                        visited.find(parentMap[node]) == visited.end()) {
                        q.push(parentMap[node]);
                        visited.insert(parentMap[node]);
                    }
                }
                currentDistance++;
            }
    
            return result;        
        }
    };