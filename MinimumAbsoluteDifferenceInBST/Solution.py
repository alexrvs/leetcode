# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.prev = 0
        self.diff = 0
        
    def helper(self, node):
        if node == None:
            return
        self.helper(node.left)
        if self.prev >= 0:
            curDiff = node.val - self.prev
            if self.diff > curDiff:
                self.diff = curDiff
        self.prev = node.val
        self.helper(node.right)
        return
        
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 0
        node = root
        while node.right != None:
            node = node.right
        self.prev = -1
        self.diff = node.val
        self.helper(root)
        return self.diff