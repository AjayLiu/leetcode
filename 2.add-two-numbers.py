#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val: int=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode()
        original_pointer = ans
        carry = 0
        is_head = True
        while(l1 != None or l2 != None):

            if (is_head):
                is_head = False
            else:
                ans.next = ListNode()
                ans = ans.next

            sum_of_nodes = (l1.val if l1 != None else 0) + (l2.val if l2 != None else 0) + carry
            ans.val = sum_of_nodes % 10
            carry = int(sum_of_nodes / 10)


            if(l1 != None and l1.next != None):
                l1 = l1.next
            else:
                l1 = None
            if(l2 != None and l2.next != None):
                l2 = l2.next
            else:
                l2 = None

        if(carry > 0):
            ans.next = ListNode(carry)
        
        return original_pointer

# testAns = (Solution().addTwoNumbers(ListNode(2, ListNode(4, ListNode(3))), ListNode(5, ListNode(6, ListNode(4)))))
# testAns = (Solution().addTwoNumbers(ListNode(9, ListNode(9, ListNode(9))), ListNode(9, ListNode(9, ListNode(9, ListNode(9))))))
# while(testAns != None):
#     print(testAns.val)
#     testAns = testAns.next

# @lc code=end

