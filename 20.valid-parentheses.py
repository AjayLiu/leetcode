#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {
            "{":"}",
            "(":")",
            "[":"]"
        }

        for i in range(len(s)):
            c = s[i]
            if(c in pairs):
                stack.append(c)
            else:
                if(len(stack) > 0 and pairs.get(stack[len(stack)-1]) == c):
                    stack.pop()
                else:
                    return False
        
        return len(stack) == 0    
# print(Solution().isValid("{[]}"))
# @lc code=end

