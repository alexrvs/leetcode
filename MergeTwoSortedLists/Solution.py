# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        node1 = l1
        node2 = l2
        head = None
        cur = None
        if node1 == None:
            return node2
        if node2 == None:
            return node1
        if node1.val < node2.val:
            cur = node1
            node1 = node1.next
        else:
            cur = node2
            node2 = node2.next
        head = cur
        while node1 != None and node2 != None:
            if node1.val < node2.val:
                cur.next = node1
                node1 = node1.next
            else:
                cur.next = node2
                node2 = node2.next
            cur = cur.next
        if node1 == None:
            cur.next = node2
        if node2 == None:
            cur.next = node1
        return head
