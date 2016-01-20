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
def odd_even_list(head)
    oHead = head
    return head if oHead == nil
    eHead = head.next
    return head if eHead == nil
    oTail = oHead
    eTail = eHead
    cur = eTail.next
    oTail.next = nil
    eTail.next = nil
    cnt = 1
    while cur != nil do
        if cnt % 2 == 1 then
            oTail.next = cur
            cur = cur.next
            oTail = oTail.next
            oTail.next = nil
        else
            eTail.next = cur
            cur = cur.next
            eTail = eTail.next
            eTail.next = nil
        end
        cnt += 1
    end
    oTail.next = eHead
    return oHead
end