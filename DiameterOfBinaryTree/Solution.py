# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def __init__(self):
        self.maxDiameter = 0
        
    def helper(self, node):
        if node == None:
            return 0
        l = self.helper(node.left)
        r = self.helper(node.right)
        if l + r > self.maxDiameter:
            self.maxDiameter = l + r
        res = l
        if res < r:
            res = r
        return res + 1
    
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxDiameter = 0
        self.helper(root)
        return self.maxDiameter