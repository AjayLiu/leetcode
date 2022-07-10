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
    
    bool isValidNode(TreeNode* root, long lessThan, long greaterThan) {
        if(!root)
            return true;
        
        int num = root->val;
        if(num >= lessThan || num <= greaterThan){
            return false;
        }
        
        return isValidNode(root->left, num, greaterThan) && isValidNode(root->right, lessThan, num);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, LONG_MAX, LONG_MIN);
    }
};