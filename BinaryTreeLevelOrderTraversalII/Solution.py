# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.res = []

    def helper(self, node, level):
        if node == None:
            return
        l = len(self.res)
        if level >= l:
            levelRes = []
            self.res.append(levelRes)
        self.res[level].append(node.val)
        self.helper(node.left, level + 1)
        self.helper(node.right, level + 1)
        return

    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.helper(root, 0)
        return list(reversed(self.res))
