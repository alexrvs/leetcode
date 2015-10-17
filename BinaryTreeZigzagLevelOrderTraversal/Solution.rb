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
def helper(res, node, l)
    return if node == nil
    res << [] if l >= res.length
    res[l] << node.val
    helper(res, node.left, l + 1)
    helper(res, node.right, l + 1)
    return
end

def zigzag_level_order(root)
    res = []
    helper(res, root, 0)
    i = 1
    while i < res.length do
        res[i] = res[i].reverse
        i += 2
    end
    return res
end
