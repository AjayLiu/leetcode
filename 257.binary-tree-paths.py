#
# @lc app=leetcode id=257 lang=python3
#
# [257] Binary Tree Paths
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
    def dfs(self, root:TreeNode, history=""):
        new_history = history + str(root.val)
        if root.left == None and root.right == None:
            return [new_history]
        if root.left == None:
            return self.dfs(root.right, new_history+"->")
        if root.right == None:
            return self.dfs(root.left, new_history+"->")
        my_list = []
        for i in self.dfs(root.left, new_history+"->"):
            my_list.append(i)
        for i in self.dfs(root.right, new_history+"->"):
            my_list.append(i)
        return my_list

    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        return self.dfs(root)

# print(Solution().binaryTreePaths(TreeNode(1, TreeNode(2, TreeNode(4, TreeNode(8)), TreeNode(5)), TreeNode(3, TreeNode(6), TreeNode(7)))))
# print(Solution().dfs(TreeNode(1, TreeNode(2, TreeNode(4, TreeNode(8)), TreeNode(5)), TreeNode(3, TreeNode(6), TreeNode(7)))))

# @lc code=end

