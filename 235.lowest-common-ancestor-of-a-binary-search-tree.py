#
# @lc app=leetcode id=235 lang=python3
#
# [235] Lowest Common Ancestor of a Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        min_target = min(p.val, q.val)
        max_target = max(p.val, q.val)
        while(root):
            if min_target > root.val and max_target > root.val:
                root = root.right
            elif min_target < root.val and max_target < root.val:
                root = root.left
            else:
                return root

# @lc code=end

