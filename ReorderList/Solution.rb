# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

def reverse_list(head)
    reverse = nil
    while head != nil do
        node = head
        head = head.next
        node.next = reverse
        reverse = node
    end
    return reverse
end

# @param {ListNode} head
# @return {Void} Do not return anything, modify head in-place instead.
def reorder_list(head)
    return if head == nil || head.next == nil
    slow = head
    fast = head
    while fast.next != nil && fast.next.next != nil do
        fast = fast.next.next
        slow = slow.next
    end
    fast = slow.next
    slow.next = nil
    fast = reverse_list(fast)
    while fast != nil do
        slow = head.next
        head.next = fast
        fast = fast.next
        head.next.next = slow
        head = slow
    end
    return
end
