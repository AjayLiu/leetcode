#
# @lc app=leetcode id=100 lang=python3
#
# [100] Same Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        if p == None or q == None:
            return False
        if p.left == None and q.left == None and \
            p.right == None and q.right == None:
            return p.val == q.val
        return p.val == q.val and self.isSameTree(p.left,q.left) and \
            self.isSameTree(p.right, q.right)

# @lc code=end

