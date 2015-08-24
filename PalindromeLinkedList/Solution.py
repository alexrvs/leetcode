# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
  def isPalindrome(self, head):
    """
    :type head: ListNode
    :rtype: bool
    """
    if ( head == None ):
      return True

    fast = head
    slow = head

    while ( fast != None and fast.next != None ):
      fast = fast.next.next
      slow = slow.next

    if ( fast != None ):
      slow = slow.next

    tmp = None
    reverse = None

    while ( slow != None ):
      tmp = slow
      slow = slow.next
      tmp.next = reverse
      reverse = tmp

    slow = head

    while ( reverse != None ):
      if ( reverse.val != slow.val ):
        return False
      reverse = reverse.next
      slow = slow.next

    return True

