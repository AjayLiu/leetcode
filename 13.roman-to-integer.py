#
# @lc app=leetcode id=13 lang=python3
#
# [13] Roman to Integer
#

# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        sum = 0
        dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        prev_val = 0
        for i in range(len(s)-1, -1, -1):
            this_val = dict[s[i]]
            sum += this_val * (1, -1)[this_val < prev_val] 
            prev_val = this_val
        return sum  

# print(Solution().romanToInt('MCMXCIV'))


# @lc code=end

