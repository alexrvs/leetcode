# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

def merge(l1, l2)
    return l2 if l1 == nil
    return l1 if l2 == nil
    head = nil
    tail = nil
    tmp = nil
    while (l1 != nil && l2 != nil) do
        if l1.val < l2.val
            tmp = l1
            l1 = l1.next
        else
            tmp = l2
            l2 = l2.next
        end
        if head == nil
            head = tmp
        else
            tail.next = tmp
        end
        tail = tmp
    end
    tail.next = l2 if l1 == nil
    tail.next = l1 if l2 == nil
    return head
end

def mergeSort(node)
    return node if node == nil || node.next == nil
    fast = node
    slow = node
    prev = nil
    while fast != nil && fast.next != nil do
        fast = fast.next.next
        prev = slow
        slow = slow.next
    end
    prev.next = nil
    return merge(mergeSort(node), mergeSort(slow))
end

# @param {ListNode} head
# @return {ListNode}
def sort_list(head)
    return mergeSort(head)
end
