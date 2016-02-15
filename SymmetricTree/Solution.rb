# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def helper(l, r)
    return true if l == nil && r == nil
    return false if l == nil || r == nil
    return false if l.val != r.val
    return helper(l.left, r.right) && helper(l.right, r.left)
end

# @param {TreeNode} root
# @return {Boolean}
def is_symmetric(root)
    return true if root == nil
    return helper(root.left, root.right)
end
