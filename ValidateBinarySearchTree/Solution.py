# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.nums = []

    def helper(self, node):
        if node == None:
            return
        self.helper(node.left)
        self.nums.append(node.val)
        self.helper(node.right)

    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.helper(root)
        l = len(self.nums)
        for i in range(1, l):
            if self.nums[i - 1] >= self.nums[i]:
                return False
        return True
