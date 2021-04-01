#
# @lc app=leetcode id=110 lang=python3
#
# [110] Balanced Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_deepest_height(self, root: TreeNode)-> int:
        if root == None:
            return 0
        return max(self.get_deepest_height(root.left) + 1, self.get_deepest_height(root.right)+1)

    def isBalanced(self, root: TreeNode) -> bool:
        if root == None:
            return True
        return self.isBalanced(root.left) and self.isBalanced(root.right) and \
            abs(self.get_deepest_height(root.left) - self.get_deepest_height(root.right)) <= 1
# @lc code=end

