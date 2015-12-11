# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head == None:
            return
        cur = head
        while cur != None:
            node = RandomListNode(cur.label)
            node.next = cur.next
            cur.next = node
            cur = node.next
        cur = head
        while cur != None:
            node = cur.next
            if cur.random != None:
                node.random = cur.random.next
            cur = node.next
        res = None
        tail = None
        cur = head
        while cur != None:
            node = cur.next
            if res == None:
                res = node
            else:
                tail.next = node
            tail = node
            cur.next = node.next
            cur = cur.next
        return res
