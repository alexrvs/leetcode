# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head, reverse):
        while head != None:
            temp = head.next
            head.next = reverse
            reverse = head
            head = temp
        return reverse
        
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        start = head
        end = head
        prev = None
        i = 1
        while i < m or i < n:
            if i < m and start != None:
                prev = start
                start = start.next
            if i < n and end != None:
                end = end.next
            i += 1
        reverse = end.next
        end.next = None
        start = self.reverseList(start, reverse)
        if prev == None:
            head = start
        else:
            prev.next = start
        return head