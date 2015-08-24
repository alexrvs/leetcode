# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {Boolean}
def is_palindrome(head)
    if head == nil
        return true
    end
    fast = head
    slow = head
    while ( fast != nil && fast.next != nil )
        fast = fast.next.next
        slow = slow.next
    end
    if ( fast != nil )
        slow = slow.next
    end
    tmp = nil
    reverse = nil
    while ( slow != nil )
        tmp = slow
        slow = slow.next
        tmp.next = reverse
        reverse = tmp
    end
    slow = head
    while ( reverse != nil )
        if ( reverse.val != slow.val )
            return false
        end
        reverse = reverse.next
        slow = slow.next
    end
    return true
end
