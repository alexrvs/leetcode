# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def helper(view, node, layer)
    return if nil == node
    if layer > view.length
        view << node.val
    end
    helper(view, node.right, layer + 1)
    helper(view, node.left, layer + 1)
end

# @param {TreeNode} root
# @return {Integer[]}
def right_side_view(root)
    view = []
    helper(view, root, 1)
    return view
end
