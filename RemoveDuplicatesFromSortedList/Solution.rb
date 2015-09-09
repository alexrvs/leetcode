# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}
def delete_duplicates(head)
    return head if head == nil
    c = head
    n = c.next
    while n != nil do
        if c.val != n.val
            c.next = n
            c = n
        else
            c.next = nil
        end
        n = n.next
    end
    return head
end
