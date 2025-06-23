
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

// DFS approach : O(NlogN) time complexity, O(N) space complexity
// where N is the number of nodes in the tree.
class Solution {
    private:
     void verticalTraversalHelper(TreeNode* root, int row, int col,
                                  map<int, map<int, vector<int>>>& mp) {
         if (!root) return;
 
         mp[col][row].push_back({root->data});
 
         if (root->left)
             verticalTraversalHelper(root->left, row + 1, col - 1, mp);
         if (root->right)
             verticalTraversalHelper(root->right, row + 1, col + 1, mp);
     }
 
    public:
     vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> ans;
         map<int, map<int, vector<int>>> mp;
 
         verticalTraversalHelper(root, 0, 0, mp);
 
             for (auto& [col, rowMap] : mp) {
             vector<int> temp;
             for (auto& [row, vec] : rowMap) {
                 sort(vec.begin(), vec.end()); // sort if multiple nodes at same (col,row)
                 temp.insert(temp.end(), vec.begin(), vec.end()); // insert into column
             }
             ans.push_back(temp); // final column vector
         }
 
         return ans;
     }
 };