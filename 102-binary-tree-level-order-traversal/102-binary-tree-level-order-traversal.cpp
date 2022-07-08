/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            vector<int> level;
            
            int startSize = q.size();
            
            for(int i = 0; i < startSize; i++){
                TreeNode* top = q.front();
                q.pop();
                level.emplace_back(top->val);
                
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            
            
            ans.emplace_back(level);
        }
        
        return ans;
    }
};