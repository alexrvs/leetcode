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
def min_depth(root)
    return 0 if root == nil
    return 1 if root.left == nil && root.right == nil
    l = -1
    r = -1
    l = min_depth(root.left) if root.left != nil
    r = min_depth(root.right) if root.right != nil
    return 1 + l if r == -1
    return 1 + r if l == -1
    return 1 + l if l < r
    return 1 + r
end
