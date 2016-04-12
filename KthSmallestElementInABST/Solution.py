# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.res = 0

    def helper(self, node, n, k):
        if n >= k or node == None:
            return n
        n = self.helper(node.left, n, k)
        n += 1
        if n == k:
            self.res = node.val
        return self.helper(node.right, n, k)

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.helper(root, 0, k)
        return self.res
