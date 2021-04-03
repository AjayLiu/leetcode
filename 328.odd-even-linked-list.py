#
# @lc app=leetcode id=328 lang=python3
#
# [328] Odd Even Linked List
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        def every_other_node(head: ListNode)->ListNode:
            original_head = head
            while(head != None):
                if head.next and head.next.next:
                    head.next = head.next.next
                head = head.next
            return original_head
        ans = every_other_node(head.next)
        # ans.next = every_other_node(head.next)
        return ans

# @lc code=end

