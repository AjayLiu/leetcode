#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode()
        ans_pointer = ans
        p1 = l1
        p2 = l2
        while p1 or p2:
            add_first = False
            if p1 and not p2:
                add_first = True
            elif p1 and p2:
                add_first = p1.val <= p2.val
            if add_first:
                ans_pointer.next = ListNode(p1.val)
                p1 = p1.next
            else:
                ans_pointer.next = ListNode(p2.val)
                p2 = p2.next
            ans_pointer = ans_pointer.next
        return ans.next
# @lc code=end

