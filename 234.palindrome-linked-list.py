#
# @lc app=leetcode id=234 lang=python3
#
# [234] Palindrome Linked List
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        def reversed_list(head: ListNode):
            prev = None
            while head != None:
                old_next = head.next 
                head.next = prev
                prev = head
                head = old_next
            return prev

        fast = head
        slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        slow = reversed_list(slow)
        fast = head

        while slow:
            if slow.val != fast.val:
                return False
            slow = slow.next
            fast = fast.next
        
        return True
# @lc code=end

