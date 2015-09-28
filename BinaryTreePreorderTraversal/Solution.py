# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self, node, vals):
        if node == None:
            return
        vals.append(node.val)
        self.helper(node.left, vals)
        self.helper(node.right, vals)
        return

    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        vals = []
        self.helper(root, vals)
        return vals
