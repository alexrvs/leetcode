# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.view = []

    def helper(self, node, layer):
        if None == node:
            return
        l = len(self.view)
        if layer > l:
            self.view.append(node.val)
        self.helper(node.right, layer + 1)
        self.helper(node.left, layer + 1)

    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.helper(root, 1)
        return self.view
