# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[]}
def helper(node, vals)
    return if node == nil
    vals << node.val
    helper(node.left, vals)
    helper(node.right, vals)
    return
end

def preorder_traversal(root)
    vals = []
    helper(root, vals)
    return vals
end
