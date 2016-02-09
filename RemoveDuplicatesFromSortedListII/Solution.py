# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        rHead = None
        rTail = None
        vHead = head
        vTail = None
        while vHead != None:
            uniq = True
            vTail = vHead
            while vTail.next != None:
                if vTail.next.val != vHead.val:
                    break
                else:
                    uniq = False
                    vTail = vTail.next
            if uniq == True:
                if rHead == None:
                    rHead = vHead
                else:
                    rTail.next = vHead
                rTail = vHead
            vHead = vTail.next

        if rTail != None:
            rTail.next = None
        return rHead

