# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        oHead = head
        eHead = head.next
        if eHead == None:
            return head
        cnt = 1
        cur = eHead.next
        oTail = oHead
        eTail = eHead
        oTail.next = None
        eTail.next = None
        while cur != None:
            if cnt % 2 == 1:
                oTail.next = cur
                cur = cur.next
                oTail = oTail.next
                oTail.next = None
            else:
                eTail.next = cur
                cur = cur.next
                eTail = eTail.next
                eTail.next = None
            cnt += 1
        oTail.next = eHead
        return oHead