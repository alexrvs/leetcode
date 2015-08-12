# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
  result = nil
  header = nil
  c = 0
  while true
    num1 = 0
    num2 = 0
    if (l1 != nil)
      num1 = l1.val
      l1 = l1.next
    end
    if (l2 != nil)
      num2 = l2.val
      l2 = l2.next
    end
    sum = num1 + num2 + c
    digit = sum%10
    c = sum/10
    node = ListNode.new(digit)
    if (result == nil)
      result = node
      header = result
    else
      result.next = node
      result = result.next
    end
    if (l1 == nil && l2 == nil)
      break
    end
  end
  if (c != 0)
    node = ListNode.new(c)
    result.next = node
  end
  return header
end
