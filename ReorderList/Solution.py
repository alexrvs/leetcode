# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        reverse = None
        node = head
        while node != None:
            head = node.next
            node.next = reverse
            reverse = node
            node = head
        return reverse

    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return
        slow = head
        fast = head
        while fast.next != None and fast.next.next != None:
            fast = fast.next.next
            slow = slow.next
        fast = slow.next
        slow.next = None
        fast = self.reverseList(fast)
        slow = head
        while fast != None:
            tmp = slow.next
            slow.next = fast
            fast = fast.next
            slow.next.next = tmp
            slow = tmp
        return


