# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        reverse = None
        node = head
        while node != None:
            head = node.next
            node.next = reverse
            reverse = node
            node = head
        return reverse
