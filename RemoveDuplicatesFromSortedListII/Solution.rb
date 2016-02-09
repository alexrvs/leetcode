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
    rHead = nil
    rTail = nil
    vHead = head
    vTail = nil
    while vHead != nil do
        uniq = true
        vTail = vHead
        while vTail.next != nil do
            if vTail.next.val != vHead.val then
                break
            else
                uniq = false
                vTail = vTail.next
            end
        end
        if uniq == true then
            if rHead == nil then
                rHead = vHead
            else
                rTail.next = vHead
            end
            rTail = vHead
        end
        vHead = vTail.next
    end
    rTail.next = nil if rTail != nil
    return rHead
end
