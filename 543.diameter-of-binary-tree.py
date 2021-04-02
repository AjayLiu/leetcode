#
# @lc app=leetcode id=543 lang=python3
#
# [543] Diameter of Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        big = [0]
        def deepestHeight(root: TreeNode) -> int:
            if not root:
                return -1 
            left = deepestHeight(root.left)
            right = deepestHeight(root.right)
            big[0] = max(big[0], left + right + 2)
            return 1 + max(left, right)

        deepestHeight(root)
        return big[0]

# print(Solution().diameterOfBinaryTree(TreeNode(1, TreeNode(2))))
# @lc code=end

