#
# @lc app=leetcode id=202 lang=python3
#
# [202] Happy Number
#

# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        def add_digits_squared(num):
            ans = 0
            while num // 10 > 0:
                ans += (num % 10)**2
                num //= 10
            return ans + num**2
        
        while n not in seen or n == 1 or n // 10 > 0:
            if n == 1:
                return True
            seen.add(n)
            n = add_digits_squared(n)
        return False

# @lc code=end