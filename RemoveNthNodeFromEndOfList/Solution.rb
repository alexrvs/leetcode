# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
    dummy = ListNode.new(-1)
    dummy.next = head
    tail = dummy
    node = dummy
    while n > 0
        tail = tail.next
        n -= 1
    end
    while tail.next != nil
        node = node.next
        tail = tail.next
    end
    node.next = node.next.next
    return dummy.next
end
