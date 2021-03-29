#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
from typing import List

class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complement_dict = {}
        for i in range(len(nums)):
            num = nums[i]
            complement = target - num
            
            if complement in complement_dict:
                return [complement_dict.get(complement), i]
            complement_dict[num] = i

            
    # print(twoSum([], [1,2,2,3,4,1,4,2], 5))
    
# @lc code=end