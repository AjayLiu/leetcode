#
# @lc app=leetcode id=392 lang=python3
#
# [392] Is Subsequence
#

# @lc code=start
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ptr = 0
        if len(s) == 0:
            return True
        if len(t) == 0:
            return False
        for c in t:
            if c == s[ptr]:
                ptr+=1
            if ptr == len(s):
                return True
        return False
# @lc code=end

