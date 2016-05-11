# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

class BSTIterator
    # @param {TreeNode} root
    def initialize(root)
        @stack = []
        helper(root)
    end

    def helper(node)
        while node != nil do
            @stack << node
            node = node.left
        end
    end

    # @return {Boolean}
    def has_next
        return (@stack.length != 0)
    end

    # @return {Integer}
    def next
        node = @stack.pop
        helper(node.right)
        return node.val
    end
end

# Your BSTIterator will be called like this:
# i, v = BSTIterator.new(root), []
# while i.has_next()
#    v << i.next
# end
