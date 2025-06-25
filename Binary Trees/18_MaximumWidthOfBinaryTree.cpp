class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            int ans = 0;
    
            if(!root) return ans;
    
            queue<pair<TreeNode*, long long>> q;
    
            q.push({root, 0});
    
            while(!q.empty()){
                int size = q.size();
                int first, last;
                long long mmin = q.front().second;
    
                for(int i = 0; i < size; i++){
                    long long line = q.front().second - mmin;
                    TreeNode* node = q.front().first;
                    q.pop();
    
                    if(i == 0) first = line;
                    if(i == size - 1) last = line;
    
                    if(node->left) q.push({node->left, 2*line + 1});
                    if(node->right) q.push({node->right, 2*line + 2});
                }
    
                ans = max(ans, last - first + 1);
            }
    
            return ans;       
        }
    };