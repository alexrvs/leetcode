# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if root == None:
            return
        self.flatten(root.left)
        self.flatten(root.right)
        leftTail = root.left
        if leftTail != None:
            while leftTail.right != None:
                leftTail = leftTail.right
            leftTail.right = root.right
            root.right = root.left
            root.left = None
        return
