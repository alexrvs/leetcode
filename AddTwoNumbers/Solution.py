# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        result = None
        head = None
        c = 0

        while True:
            num1 = 0
            num2 = 0
            if (l1 is not None):
                num1 = l1.val
                l1 = l1.next
            if (l2 is not None):
                num2 = l2.val
                l2 = l2.next
            sum = num1 + num2 + c
            digit = sum % 10
            c = sum / 10
            node = ListNode(digit)
            if (result is not None):
                result.next = node
                result = result.next
            else:
                result = node
                head = result
            if (l1 is None and l2 is None):
                break

        if (c != 0):
            node = ListNode(c)
            result.next = node

        return head
