# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        c = head
        n = c.next
        while n != None:
            if c.val != n.val:
                c.next = n
                c = n
            else:
                c.next = None
            n = n.next
        return head
