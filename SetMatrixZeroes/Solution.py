class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        r = len(matrix)
        if r == 0:
            return
        c = len(matrix[0])
        firstRow = 1
        firstCol = 1
        for i in range(0, r):
            if matrix[i][0] == 0:
                firstCol = 0
            for j in range(0, c):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                    if i == 0:
                        firstRow = 0
        for i in range(1, r):
            for j in range(1, c):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if firstRow == 0:
            for j in range(0, c):
                matrix[0][j] = 0
        if firstCol == 0:
            for i in range(0, r):
                matrix[i][0] = 0
        return
