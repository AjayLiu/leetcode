#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        s = str(x)[::-1]
        if(x < 0):
            s = s[:len(s)-1]
            s = "-" + s

        ignore_zeroes = True
        ans = ""
        if x == 0 :
            return 0
        for digit in s:
            if(digit != '0' or not ignore_zeroes):
                ignore_zeroes=False
                ans = ans + digit

        ans_int = int(ans)
        if(ans_int > pow(2, 31)-1 or ans_int < -pow(2, 31)):
            return 0

        return ans_int
    # print(reverse([], 1534236469))
# @lc code=end

