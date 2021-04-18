#
# @lc app=leetcode id=997 lang=python3
#
# [997] Find the Town Judge
#

# @lc code=start

from typing import List
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N == 1:
            return 1

        trustiness = {} # index is person, value is num of trusts
        for i in trust:
            trustiness[i[0]] = -2*N
            if i[1] not in trustiness:
                trustiness[i[1]] = 0
            trustiness[i[1]] += 1

        for i in trust:
            if trustiness[i[1]] == N-1:
                return i[1]
        return -1

# @lc code=end

