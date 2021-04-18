#
# @lc app=leetcode id=746 lang=python3
#
# [746] Min Cost Climbing Stairs
#

# @lc code=start
from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = []
        for i in range(len(cost)):
            if i == 0:
                dp.append(0)
            elif i == 1:
                dp.append(min(cost[i-1], cost[i]))
            else:
                dp.append(min(dp[i-2] + cost[i-1], dp[i-1] + cost[i]))
        return dp[len(dp)-1]

# print(Solution().minCostClimbingStairs([10,15,20]))
# print(Solution().minCostClimbingStairs([1,100,1,1,1]))
# print(Solution().minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]))
# @lc code=end

