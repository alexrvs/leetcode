# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getLength(self, head):
        length = 0
        while head is not None:
            head = head.next
            length += 1
        return length

    def reverseList(self, head):
        if head is None or head.next is None:
            return head
        reverse = None
        node = None
        while head is not None:
            node = head
            head = head.next
            node.next = reverse
            reverse = node
        return reverse

    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        l = self.getLength(head)
        if l < k:
            return head
        rHead = None
        rTail = None
        sHead = None
        sTail = None
        while head is not None:
            sHead = head
            sTail = head
            cnt = k - 1
            while cnt > 0 and sTail.next is not None:
                sTail = sTail.next
                cnt -= 1
            if cnt > 0:
                break
            head = sTail.next
            sTail.next = None
            sHead = self.reverseList(sHead)
            if rHead is None:
                rHead = sHead
                rTail = sHead
            else:
                rTail.next = sHead
            while rTail.next is not None:
                rTail = rTail.next
        if rTail is not None:
            rTail.next = head
        return rHead
