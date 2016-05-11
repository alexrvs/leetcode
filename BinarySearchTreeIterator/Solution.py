# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        self.helper(root)

    def helper(self, node):
        while node != None:
            self.stack.append(node)
            node = node.left
        return

    def hasNext(self):
        """
        :rtype: bool
        """
        l = len(self.stack)
        return (l != 0)

    def next(self):
        """
        :rtype: int
        """
        node = self.stack.pop()
        self.helper(node.right)
        return node.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
