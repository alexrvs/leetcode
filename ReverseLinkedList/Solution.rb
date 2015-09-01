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
def reverse_list(head)
    reverse = nil
    node = head
    while node != nil
        head = node.next
        node.next = reverse
        reverse = node
        node = head
    end
    return reverse
end
