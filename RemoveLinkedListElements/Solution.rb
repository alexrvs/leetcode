# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} val
# @return {ListNode}
def remove_elements(head, val)
    dummy = ListNode.new()
    dummy.next = head
    cur = dummy
    while cur.next != nil do
        if cur.next.val == val then
            cur.next = cur.next.next
        else
            cur = cur.next
        end
    end
    return dummy.next
end
