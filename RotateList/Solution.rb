# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def rotate_right(head, k)
    return head if head == nil
    tail = head
    cnt = 1
    while tail.next != nil
        tail = tail.next
        cnt += 1
    end
    tail.next = head
    step = cnt - k%cnt
    while (step > 0)
        head = head.next
        tail = tail.next
        step -= 1
    end
    tail.next = nil
    return head
end
