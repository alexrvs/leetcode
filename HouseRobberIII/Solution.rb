# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def helper(node)
    return 0, 0 if node == nil
    lw, lwo = helper(node.left)
    rw, rwo = helper(node.right)
    w = node.val + lwo + rwo
    wo = 0
    sum = lw + rw
    wo = sum if wo < sum
    sum = lw + rwo
    wo = sum if wo < sum
    sum = lwo + rw
    wo = sum if wo < sum
    sum = lwo + rwo
    wo = sum if wo < sum
    return w, wo
end

# @param {TreeNode} root
# @return {Integer}
def rob(root)
    w, wo = helper(root)
    return w if w > wo
    return wo
end
