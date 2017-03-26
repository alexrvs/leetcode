# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.sum = 0
        
    def helper(self, node):
        if None == node:
            return
        self.helper(node.right)
        self.sum += node.val
        node.val = self.sum
        self.helper(node.left)
        return
        
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.helper(root)
        return root