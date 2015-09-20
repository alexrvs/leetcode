# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self, root):
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        left = self.helper(root.left)
        right = self.helper(root.right)
        if left != -1 and right != -1:
            diff = left - right if left > right else right - left
            if diff <= 1:
                height = left + 1 if left > right else right + 1
                return height
        return -1

    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root) != -1
