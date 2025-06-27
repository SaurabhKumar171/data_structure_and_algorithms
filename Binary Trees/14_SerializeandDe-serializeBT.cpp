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
    public:
        string serialize(TreeNode* root) {
            if(!root) return "";
            string s = "";
    
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                TreeNode* currentNode = q.front();
                q.pop();
                if(currentNode == nullptr) s.append("#,");
                else s.append(to_string(currentNode->data) + ',');
    
                if(currentNode != nullptr){
                    q.push(currentNode->left);
                    q.push(currentNode->right);
                }
            }
    
           return s;
        }
    
        TreeNode* deserialize(string data) {
            if(data.empty()) return nullptr;
    
            istringstream s(data);
            string str;
            getline(s, str, ',');
    
            TreeNode* root = new TreeNode(stoi(str));
    
            queue<TreeNode*> q;
            q.push(root);
    
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
    
                getline(s, str, ',');
                if(str != "#"){
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
    
                getline(s, str, ',');
                if(str != "#"){
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
    
            return root;
        }
    };
    
    
    /*
    * Your Codec object will be instantiated and called as such:
    * Codec* ser = new Codec();
    * Codec* deser = new Codec();
    * string tree = ser->serialize(root);
    * TreeNode* ans = deser->deserialize(tree);
    * return ans;
    */