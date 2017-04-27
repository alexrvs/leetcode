:w
k# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __int__(self):
        self.tilt = 0
        
    def helper(self, node):
        if None == node:
            return 0
        l = self.helper(node.left)
        r = self.helper(node.right)
        diff = l - r
        if diff < 0:
            diff = -diff
        self.tilt += diff
        return l + r + node.val
    
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.tilt = 0
        self.helper(root)
        return self.tilt