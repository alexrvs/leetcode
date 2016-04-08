class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        h = l / 2
        w = h
        if l % 2 != 0:
            w += 1
        for i in range(0, h):
            for j in range(0, w):
                t = matrix[i][j]
                matrix[i][j] = matrix[l - 1 - j][i]
                matrix[l - 1 - j][i] = matrix[l - 1 - i][l - 1 - j]
                matrix[l - 1 - i][l - 1 - j] = matrix[j][l - 1 - i]
                matrix[j][l - 1 - i] = t
