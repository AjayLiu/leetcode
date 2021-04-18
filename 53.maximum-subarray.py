#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best_so_far = nums[0]
        prev_best = nums[0]
        for i in range(len(nums)):
            if i != 0:
                prev_best = max(prev_best + nums[i], nums[i])
                best_so_far = max(best_so_far, prev_best)
        return best_so_far

# print(Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
# print(Solution().maxSubArray([-2,1,-3]))
# print(Solution().maxSubArray([1,2,-1]))
# print(Solution().maxSubArray([5,4,-1,7,8]))

# @lc code=end

