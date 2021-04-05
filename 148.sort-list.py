#
# @lc app=leetcode id=148 lang=python3
#
# [148] Sort List
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # store the linkedlist as a list
        my_list = []
        while head:
            my_list.append(head.val)
            head = head.next

        my_list.sort()
        
        # construct linkedlist from this list
        original_head = ListNode()
        ptr = original_head
        for i in my_list:
            ptr.next = ListNode(i)
            ptr = ptr.next

        return original_head.next


# @lc code=end

