# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        fast = head
        slow = head

        while True :
            if fast != None :
                fast = fast.next
            if fast != None :
                fast = fast.next
            if fast == None :
                return fast
            slow = slow.next
            if fast == slow :
                break

        fast = head
        while fast != slow :
            fast = fast.next
            slow = slow.next
        return fast
