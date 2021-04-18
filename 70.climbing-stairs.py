#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        fib = []
        for i in range(n):
            if i is 0:
                fib.append(1)
            elif i is 1:
                fib.append(2)
            else:
                fib.append(fib[i-2]+fib[i-1])
        
        return fib[n-1]

# @lc code=end

