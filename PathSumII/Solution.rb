# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def helper(res, path, node, sum)
    return if node == nil
    path << node.val
    if node.val == sum && ! node.left && ! node.right then
        find = Array.new(path)
        res << find
    else
        helper(res, path, node.left, sum - node.val)
        helper(res, path, node.right, sum - node.val)
    end
    path.pop
end

# @param {TreeNode} root
# @param {Integer} sum
# @return {Integer[][]}
def path_sum(root, sum)
    res = []
    path = []
    helper(res, path, root, sum)
    return res
end
