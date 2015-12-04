# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

def reverse_list(head)
    return head if head == nil or head.next == nil
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
# @param {Integer} k
# @return {ListNode}
def reverse_k_group(head, k)
    return head if head == nil or head.next == nil
    r_head = nil
    r_tail = nil
    s_head = nil
    s_tail = nil
    while head != nil do
        s_head = head
        s_tail = head
        cnt = k - 1
        while cnt > 0 && s_tail.next != nil do
            s_tail = s_tail.next
            cnt -= 1
        end
        break if cnt > 0
        head = s_tail.next
        s_tail.next = nil
        s_head = reverse_list(s_head)
        if r_head == nil then
            r_head = s_head
            r_tail = s_head
        else
            r_tail.next = s_head
        end
        while r_tail.next != nil do
            r_tail = r_tail.next
        end
    end
    return head if r_head == nil
    r_tail.next = head
    return r_head
end
