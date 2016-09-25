# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 0
        l = 0
        if root.left != None and root.left.left == None and root.left.right == None:
            l = root.left.val
        else:
            l = self.sumOfLeftLeaves(root.left)
        r = self.sumOfLeftLeaves(root.right)
        return l + r
