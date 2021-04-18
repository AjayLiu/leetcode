#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [] # largest sum so far
        for i in range(len(nums)):
            if i == 0:
                dp.append(nums[0])
            else:
                dp.append(max(dp[i-1] + nums[i], nums[i]))
        return max(dp)

# print(Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
# print(Solution().maxSubArray([-2,1,-3]))
# print(Solution().maxSubArray([1,2,-1]))
# print(Solution().maxSubArray([5,4,-1,7,8]))
# @lc code=end

