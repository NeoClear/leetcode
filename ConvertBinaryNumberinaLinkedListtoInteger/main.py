class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = 0
        while head != None:
            ans = ans * 2 + head.val
            head = head.next
        return ans
