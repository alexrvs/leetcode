# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

def reverse_list(head)
    if head == nil || head.next == nil then
        return head
    end
    reverse = nil
    node = nil
    while head != nil do
        node = head
        head = head.next
        node.next = reverse
        reverse = node
    end
    return reverse
end

# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)
    if head == nil || head.next == nil then
        return head
    end
    reverse_head = nil
    reverse_tail = nil
    sub_head = nil
    sub_tail = nil
    while head != nil do
        sub_head = head
        if head.next != nil then
            sub_tail = head.next
            head = sub_tail.next
            sub_tail.next = nil
        else
            head = head.next
        end
        sub_head = reverse_list(sub_head)
        if reverse_head == nil then
            reverse_head = sub_head
            reverse_tail = sub_head
        else
            reverse_tail.next = sub_head
        end
        while reverse_tail.next != nil do
            reverse_tail = reverse_tail.next
        end
    end
    return reverse_head
end
