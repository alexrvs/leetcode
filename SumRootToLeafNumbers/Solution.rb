# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
sum = 0

def helper(node, prefix, sum)
    return sum if node == nil
    curVal = prefix * 10 + node.val
    sum += curVal if node.left == nil && node.right == nil
    sum = helper(node.left, curVal, sum)
    sum = helper(node.right, curVal, sum)
    return sum
end

def sum_numbers(root)
    return helper(root, 0, 0)
end
