# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return head
        tail = head
        cnt = 1
        while tail.next != None:
            tail = tail.next
            cnt += 1
        tail.next = head
        step = cnt - k%cnt
        while step > 0:
            head = head.next
            tail = tail.next
            step -= 1
        tail.next = None
        return head
