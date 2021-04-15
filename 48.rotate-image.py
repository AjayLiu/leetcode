#
# @lc app=leetcode id=48 lang=python3
#
# [48] Rotate Image
#

# @lc code=start
from typing import List
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n-1):
            for j in range(i,n-i-1):
                # rotate 4 at this spot                
                # print(matrix[i][j])
                # print(matrix[j][n-i-1])
                # print(matrix[n-i-1][n-j-1])
                # print(matrix[n-j-1][i])

                first = matrix[i][j]
                matrix[i][j] = matrix[n-j-1][i]
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1]
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1]
                matrix[j][n-i-1] = first
        
# Solution().rotate([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]);
# Solution().rotate([[1,2,3],[4,5,6],[7,8,9]]);
# @lc code=end

