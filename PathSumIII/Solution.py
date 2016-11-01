# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self, root, sums, target):
        cnt = 0
        if root == None:
            return cnt
        if root.val == target:
            cnt += 1
        l = len(sums)
        for i in range(0, l):
            sums[i] += root.val
            if sums[i] == target:
                cnt += 1
        sums.append(root.val)
        cnt += self.helper(root.left, sums, target)
        cnt += self.helper(root.right, sums, target)
        sums.pop()
        for i in range(0, l):
            sums[i] -= root.val
        return cnt
        
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        sums = []
        return self.helper(root, sums, sum)