#
# @lc app=leetcode id=101 lang=python3
#
# [101] Symmetric Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def areSameVal(self, root1: TreeNode, root2: TreeNode) -> bool:
        if root1 == None and root2 == None:
            return True
        if root1 == None or root2 == None:
            return False
        return root1.val == root2.val \
            and self.areSameVal(root1.left, root2.right) \
            and self.areSameVal(root1.right, root2.left)

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.areSameVal(root, root)
    
# print(Solution().isSymmetric(
#     TreeNode(1, 
#         TreeNode(2, 
#             TreeNode(3), 
#             TreeNode(4)),
#         TreeNode(2,
#             TreeNode(4),
#             TreeNode(3))
#     )
# ))

# print(Solution().isSymmetric(
#     TreeNode(1, 
#         TreeNode(2, 
#             None, 
#             TreeNode(3)),
#         TreeNode(2,
#             None,
#             TreeNode(3))
#     )
# ))

# print(Solution().isSymmetric(TreeNode(1)))

# @lc code=end

