# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self, nums, start, end):
        if start > end:
            return None
        m = start + ((end - start) >> 1)
        node = TreeNode(nums[m])
        node.left = self.helper(nums, start, m - 1)
        node.right = self.helper(nums, m + 1, end)
        return node
        
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        size = len(nums)
        if size == 0:
            return None
        return self.helper(nums, 0, size - 1)