#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start
from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return nums
        ans = []
        for i in range(len(nums)):
            copy = nums.copy()
            deleted = copy[i]
            del copy[i]

            my_permute = self.permute(copy)
            if len(my_permute) == 1:
                ans.append([deleted, my_permute[0]])
            else:
                for m in my_permute:
                    ans.append([deleted, m])

        return ans

print(Solution().permute([1,2,3]))

# @lc code=end

