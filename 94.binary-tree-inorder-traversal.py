#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
from typing import List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def helper (root: TreeNode):
            global ans
            if not root:
                return 
            helper(root.left)
            ans.append(root.val)
            print(root.val)
            helper(root.right)
        return ans
# @lc code=end

