#
# @lc app=leetcode id=617 lang=python3
#
# [617] Merge Two Binary Trees
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if not root1 and not root2:
            return None
        if not root1:
            return TreeNode(root2.val, root2.left, root2.right)
        if not root2:
            return TreeNode(root1.val, root1.left, root1.right)
        return TreeNode(root1.val+root2.val, self.mergeTrees(root1.left, root2.left), self.mergeTrees(root1.right, root2.right))
# @lc code=end

