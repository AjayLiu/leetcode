#
# @lc app=leetcode id=1046 lang=python3
#
# [1046] Last Stone Weight
#

# @lc code=start
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while(len(stones) > 1):
            big1 = max(stones)
            stones.remove(big1)
            big2 = max(stones)
            stones.remove(big2)
            stones.append(abs(big1-big2))
        return stones[0]

# print(Solution().lastStoneWeight([2,7,4,1,8,1]))

# @lc code=end

