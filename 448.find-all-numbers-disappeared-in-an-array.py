#
# @lc app=leetcode id=448 lang=python3
#
# [448] Find All Numbers Disappeared in an Array
#

# @lc code=start
from typing import List

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for i in nums:
            nums[abs(i)-1] = -abs(nums[abs(i)-1])
        ans = []
        for i in range(len(nums)):
            if (nums[i] > 0):
                ans.append(i+1)
        return ans
# @lc code=end

