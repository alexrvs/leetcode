# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
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

    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        reverseHead = None
        reverseTail = None
        subHead = None
        subTail = None
        while head is not None:
            subHead = head
            if head.next is not None:
                subTail = head.next
                head = subTail.next
                subTail.next = None
            else:
                head = head.next
            subHead = self.reverseList(subHead)
            if reverseHead is None:
                reverseHead = subHead
                reverseTail = subHead
            else:
                reverseTail.next = subHead
            while reverseTail.next is not None:
                reverseTail = reverseTail.next
        return reverseHead
