#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#

# @lc code=start
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.val:int = None
        self.beneath : MinStack = None
        self.min_so_far:int = 2**31

        self.top_of_stack : MinStack = self
        
    def push(self, val: int) -> None:        
        # print ("push " + str(val))
        old_top = self.top_of_stack
        self.top_of_stack = MinStack()
        self.top_of_stack.val = val
        self.top_of_stack.beneath = old_top
        self.top_of_stack.min_so_far = min(val, old_top.min_so_far)

    def pop(self) -> None:
        # print("pop")
        beneath_node = self.top_of_stack.beneath        
        self.top_of_stack = beneath_node
        self.min_so_far = beneath_node.min_so_far
        if not self.top_of_stack.beneath:
            self.min_so_far = 2**31



    def top(self) -> int:
        # print("top " + str(self.top_of_stack.val))
        return self.top_of_stack.val  

    def getMin(self) -> int:
        # print("min " + str(self.top_of_stack.min_so_far))
        return self.top_of_stack.min_so_far

'''
["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]\n[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
'''
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(3)
# print(obj.getMin())
# obj.push(2)
# print(obj.getMin())
# obj.push(1)
# print(obj.getMin())
# obj.push(4)
# print(obj.getMin())
# print('---------')
# obj.pop()
# print(obj.getMin())
# obj.pop()
# print(obj.getMin())
# obj.pop()
# print(obj.getMin())
# obj.pop()

# @lc code=end

