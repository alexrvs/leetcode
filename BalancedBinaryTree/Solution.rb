# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Boolean}
def helper(node)
    return 0 if node == nil
    return 1 if node.left == nil && node.right == nil
    left = helper(node.left)
    right = helper(node.right)
    if left != -1 && right != -1
        diff = left > right ? left - right : right - left
        if diff <= 1
            return 1 + (left > right ? left : right)
        end
    end
    return -1
end

def is_balanced(root)
    return helper(root) != -1
end
