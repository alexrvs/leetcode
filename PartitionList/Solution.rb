# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} x
# @return {ListNode}
def partition(head, x)
    lHead = nil
    lTail = nil
    sHead = nil
    sTail = nil
    cur = head
    while cur != nil do
        if cur.val < x then
            if sHead == nil then
                sHead = cur
            else
                sTail.next = cur
            end
            sTail = cur
            cur = cur.next
            sTail.next = nil
        else
            if lHead == nil then
                lHead = cur
            else
                lTail.next = cur
            end
            lTail = cur
            cur = cur.next
            lTail.next = nil
        end
    end
    if sTail != nil then
        sTail.next = lHead
        return sHead
    end
    return lHead
end
