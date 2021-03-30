#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = 0
        widest = 0
        seen = set()
        while(j < len(s)):
            c = s[j]
            if c not in seen:
                # print(seen)
                # print(s[i:j+1])
                seen.add(c)
            else:
                if s[i] != c:
                    seen.remove(s[i])
                    j-=1
                i+=1

            widest = max(widest, j-i+1)
            j += 1
        return widest

# print(Solution().lengthOfLongestSubstring(""))
# @lc code=end

