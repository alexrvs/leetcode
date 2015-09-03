# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        tail = dummy
        node = dummy
        while n > 0:
            tail = tail.next
            n -= 1
        while tail.next != None:
            node = node.next
            tail = tail.next
        node.next = node.next.next
        return dummy.next
