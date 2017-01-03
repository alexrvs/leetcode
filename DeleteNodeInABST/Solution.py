# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        to_del = root
        prev = None
        while to_del != None and to_del.val != key:
            prev = to_del
            if key < to_del.val:
                to_del = to_del.left
            else:
                to_del = to_del.right
        if to_del is None:
            return root
        if to_del.left is None:
            if prev is None:
                root = to_del.right
            else:
                if to_del.val < prev.val:
                    prev.left = to_del.right
                else:
                    prev.right = to_del.right
        else:
            if prev is None:
                root = to_del.left
            else:
                if to_del.val < prev.val:
                    prev.left = to_del.left
                else:
                    prev.right = to_del.left
            pred = to_del.left
            while pred.right != None:
                pred = pred.right
            pred.right = to_del.right
        return root
