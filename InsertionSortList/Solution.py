# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        prev = head
        cur = head.next
        while cur != None:
            if prev.val <= cur.val:
                prev = cur
                cur = cur.next
            else:
                insertPrev = dummy
                insertNode = dummy.next
                prev.next = cur.next
                while insertNode.val <= cur.val:
                    insertPrev = insertNode
                    insertNode = insertNode.next
                cur.next = insertNode
                insertPrev.next = cur
                cur = prev.next
        return dummy.next
