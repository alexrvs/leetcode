# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

$max = 0

def find_min(node)
    return if node == nil
    $max = node.val if node.val < $max
    find_min(node.left)
    find_min(node.right)
end

def helper(node)
    return 0 if node == nil
    left_sum = helper(node.left)
    right_sum = helper(node.right)
    cur_sum = node.val
    cur_sum += left_sum if left_sum > 0
    cur_sum += right_sum if right_sum > 0
    $max = cur_sum if cur_sum > $max
    cur_sum = node.val
    if left_sum > right_sum
        cur_sum += left_sum if left_sum > 0
    else
        cur_sum += right_sum if right_sum > 0
    end
    return cur_sum
end

# @param {TreeNode} root
# @return {Integer}
def max_path_sum(root)
    $max = 0
    find_min(root)
    helper(root)
    return $max
end
