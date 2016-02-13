# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        lHead = None
        lTail = None
        sHead = None
        sTail = None
        cur = head
        while cur != None:
            if cur.val < x:
                if sHead == None:
                    sHead = cur
                else:
                    sTail.next = cur
                sTail = cur
                cur = cur.next
                sTail.next = None
            else:
                if lHead == None:
                    lHead = cur
                else:
                    lTail.next = cur
                lTail = cur
                cur = cur.next
                lTail.next = None
        if sTail != None:
            sTail.next = lHead
            return sHead
        return lHead
