#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        valley = prices[0]
        max_profit = 0
        for i in prices:
            max_profit = max(max_profit, i-valley)
            valley = min(valley, i)

        return max_profit
        
# print(Solution().maxProfit([7,1,5,3,6,4]))
# print(Solution().maxProfit([7,6,4,3,1]))



# @lc code=end