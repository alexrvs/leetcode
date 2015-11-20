# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.max = 0

    def findMin(self, node):
        if None == node:
            return
        if node.val < self.max:
            self.max = node.val
        self.findMin(node.left)
        self.findMin(node.right)

    def helper(self, node):
        if None == node:
            return 0
        leftSum = self.helper(node.left)
        rightSum = self.helper(node.right)
        curSum = node.val
        if leftSum > 0:
            curSum += leftSum
        if rightSum > 0:
            curSum += rightSum
        if curSum > self.max:
            self.max = curSum
        curSum = node.val
        if leftSum > rightSum:
            if leftSum > 0:
                curSum += leftSum
        else:
            if rightSum > 0:
                curSum += rightSum
        return curSum

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max = 0
        self.findMin(root)
        self.helper(root)
        return self.max
