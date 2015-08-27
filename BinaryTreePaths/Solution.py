# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def __init__(self):
        self.paths = []

    def helper(self, path, node):
        if node == None :
            return
        path = path + str(node.val)
        if node.left == None and node.right == None :
            self.paths.append(path)
            return
        if node.left != None :
            self.helper(path + "->", node.left)
        if node.right != None :
            self.helper(path + "->", node.right)
        return

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        path = ""
        self.helper(path, root)
        return self.paths
