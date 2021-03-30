#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start

from typing import List
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        biggest = 0
        while(left != right):
            area = (right-left)*min(height[left], height[right])
            biggest = max(biggest, area) 
            if height[left] < height[right]:
                left+=1
            else:
                right-=1
        return biggest

# print(Solution().maxArea([1,8,9,2,5,4,8,3,7]))
# print(Solution().maxArea([4,3,2,1,4]))
# print(Solution().maxArea([1,2,1]))
# print(Solution().maxArea([1,0]))
# @lc code=end

