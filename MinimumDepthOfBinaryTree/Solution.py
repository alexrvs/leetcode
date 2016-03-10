# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        l = -1
        r = -1
        if root.left != None:
            l = self.minDepth(root.left)
        if root.right != None:
            r = self.minDepth(root.right)
        if l == -1:
            return 1 + r
        if r == -1:
            return 1 + l
        if l < r:
            return 1 + l
        else:
            return 1 + r
