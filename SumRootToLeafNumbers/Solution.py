# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.sum = 0

    def helper(self, node, prefix):
        if None == node:
            return
        curVal = prefix * 10 + node.val
        if None == node.left and None == node.right:
            self.sum += curVal
        self.helper(node.left, curVal)
        self.helper(node.right, curVal)

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.sum = 0
        self.helper(root, 0)
        return self.sum
