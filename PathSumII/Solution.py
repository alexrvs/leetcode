# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def helper(self, res, path, node, sum):
        if node == None:
            return
        path.append(node.val)
        if node.val == sum and node.left == None and node.right == None:
            find = list(path)
            res.append(find)
        else:
            self.helper(res, path, node.left, sum - node.val)
            self.helper(res, path, node.right, sum - node.val)
        path.pop()


    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        res = []
        path = []
        self.helper(res, path, root, sum)
        return res
