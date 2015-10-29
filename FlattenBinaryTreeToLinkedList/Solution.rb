# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Void} Do not return anything, modify root in-place instead.
def flatten(root)
    return if root == nil
    flatten(root.left)
    flatten(root.right)
    if root.left != nil
        left_tail = root.left
        while left_tail.right != nil do
            left_tail = left_tail.right
        end
        left_tail.right = root.right
        root.right = root.left
        root.left = nil
    end
    return
end
