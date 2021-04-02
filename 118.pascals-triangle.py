#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#

# @lc code=start

from typing import List
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans_list = []
        for width in range(1, numRows+1):
            row = [1]
            if width >= 2:
                row = [1, 1]

            for i in range(width-2):
                row.insert(1+i, ans_list[width-2][i] + ans_list[width-2][i+1])

            ans_list.append(row)

        return ans_list

# @lc code=end

