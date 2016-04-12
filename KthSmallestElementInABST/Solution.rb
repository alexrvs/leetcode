# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end
$res = 0

def helper(node, n, k)
    return n if n >= k || node == nil
    n = helper(node.left, n, k)
    n += 1
    $res = node.val if n == k
    return helper(node.right, n, k)
end

# @param {TreeNode} root
# @param {Integer} k
# @return {Integer}
def kth_smallest(root, k)
    helper(root, 0, k)
    return $res
end
