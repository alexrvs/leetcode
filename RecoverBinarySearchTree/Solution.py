# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        first = None
        second = None
        prev = None
        pred = None
        cur = root
        while cur != None:
            if prev != None and cur.val < prev.val:
                if first == None:
                    first = prev
                second = cur
            
            if cur.left != None:
                pred = cur.left
                while pred.right != None and pred.right != cur:
                    pred = pred.right
                if pred.right == cur:
                    pred.right = None
                    prev = cur
                    cur = cur.right
                else:
                    pred.right = cur
                    cur = cur.left
            else:
                prev = cur
                cur = cur.right
        
        val = first.val
        first.val = second.val
        second.val = val