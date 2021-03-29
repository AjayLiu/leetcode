#
# @lc app=leetcode id=9 lang=python3
#
# [9] Palindrome Number
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x < 0):
            return False
        s = str(x)
        reverse = s[::-1]
        return s == reverse
        
    # print(isPalindrome([], 1243431242314))
# @lc code=end

