#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
from typing import List

class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = []
        for i in range(len(nums)-1):
            num = nums[i]
            if(not num in seen):
                seen.append(num)
                complement = target - num
                try:
                    complement_index = nums.index(complement, i+1)
                except:
                    complement_index = -1

                if(complement_index != -1):
                    return [i, complement_index]
    
    # twoSum([], [1,2,2,3,4,1,4,2], 5)
# @lc code=end