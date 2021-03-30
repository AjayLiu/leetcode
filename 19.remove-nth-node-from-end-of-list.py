#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        copy = ListNode(0,head)
        left = copy
        right = copy
        distance = 0
        while right.next != None:
            if distance == n:
                left = left.next
            else:
                distance += 1 

            right = right.next
        left.next = left.next.next
        return copy.next
# @lc code=end

