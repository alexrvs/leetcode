# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def helper(paths, path, node)
  return if node == nil
  path = path + node.val.to_s
  if node.left == nil && node.right == nil
    paths << path
    return
  end
  if node.left != nil
    helper(paths, path + "->", node.left)
  end
  if node.right != nil
    helper(paths, path + "->", node.right)
  end
  return
end

# @param {TreeNode} root
# @return {String[]}
def binary_tree_paths(root)
  path = ""
  paths = []
  helper(paths, path, root)
  return paths
end
