# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def merge_two_lists(l1, l2)
    return l1 if l2 == nil
    return l2 if l1 == nil
    if l1.val < l2.val
        cur = l1
        l1 = l1.next
    else
        cur = l2
        l2 = l2.next
    end
    head = cur
    while l1 != nil && l2 != nil
        if l1.val < l2.val
            cur.next = l1
            l1 = l1.next
        else
            cur.next = l2
            l2 = l2.next
        end
        cur = cur.next
    end
    cur.next = l1 if l1 != nil
    cur.next = l2 if l2 != nil
    return head
end
