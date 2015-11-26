# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def merge(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        head = None
        tail = None
        tmp = None
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                tmp = l1
                l1 = l1.next
            else:
                tmp = l2
                l2 = l2.next
            if head == None:
                head = tmp
            else:
                tail.next = tmp
            tail = tmp
        if l1 == None:
            tail.next = l2
        if l2 == None:
            tail.next = l1
        return head

    def mergeSort(self, node):
        if node == None or node.next == None:
            return node
        fast = node
        slow = node
        prev = node
        while fast != None and fast.next != None:
            fast = fast.next.next
            prev = slow
            slow = slow.next
        prev.next = None
        return self.merge(self.mergeSort(node), self.mergeSort(slow))

    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return self.mergeSort(head)
