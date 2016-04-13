# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

$nums = []

def helper(node, nums)
    return if node == nil
    helper(node.left, nums)
    nums << node.val
    helper(node.right, nums)
end

# @param {TreeNode} root
# @return {Boolean}
def is_valid_bst(root)
    nums = []
    helper(root, nums)
    1.upto(nums.length - 1) do | i |
        return false if nums[i - 1] >= nums[i]
    end
    return true
end
