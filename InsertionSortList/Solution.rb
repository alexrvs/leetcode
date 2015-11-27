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
def insertion_sort_list(head)
    return head if head == nil
    dummy = ListNode.new(-1)
    dummy.next = head
    prev = head
    cur = head.next
    while cur != nil do
        if prev.val <= cur.val
            prev = cur
            cur = cur.next
        else
            insertPrev = dummy
            insertNode = dummy.next
            prev.next = cur.next
            while insertNode.val <= cur.val do
                insertPrev = insertNode
                insertNode = insertNode.next
            end
            cur.next = insertNode
            insertPrev.next = cur
            cur = prev.next
        end
    end
    return dummy.next
end
