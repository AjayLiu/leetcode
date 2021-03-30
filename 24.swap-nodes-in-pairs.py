#
# @lc app=leetcode id=24 lang=python3
#
# [24] Swap Nodes in Pairs
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        if head.next != None:
            first_head = head
            second_head = head.next
            third_head = head.next.next or None

            head = second_head
            head.next = first_head
            if third_head != None:
                head.next.next = self.swapPairs(third_head)
            else:
                head.next.next = None

        return head

# ans_head = (Solution().swapPairs(ListNode(1, ListNode(2, ListNode(3, ListNode(4))))))
# ans_head = (Solution().swapPairs(ListNode(1, ListNode(2))))
# ans_head = Solution().swapPairs(ListNode(None))
# while ans_head != None:
#     print(ans_head.val)
#     ans_head = ans_head.next
# @lc code=end

