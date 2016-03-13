# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self, node):
        if node == None:
            return 0, 0
        lw, lwo = self.helper(node.left)
        rw, rwo = self.helper(node.right)
        w = node.val + lwo + rwo
        wo = 0
        sum = lw + rw
        if wo < sum:
            wo = sum
        sum = lwo + rw
        if wo < sum:
            wo = sum
        sum = lw + rwo
        if wo < sum:
            wo = sum
        sum = lwo + rwo
        if wo < sum:
            wo = sum
        return w, wo

    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        w, wo = self.helper(root)
        if w > wo:
            return w
        return wo

