# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[][]}
def helper(res, node, level)
    return if node == nil
    l = res.length
    res << [] if level >= l
    res[level] << node.val
    helper(res, node.left, level + 1)
    helper(res, node.right, level + 1)
    return
end

def level_order(root)
    res = []
    helper(res, root, 0)
    return res
end
