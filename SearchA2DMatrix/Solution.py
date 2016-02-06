class Solution(object):
    def search(self, matrix, target):
        l = 0
        r = len(matrix)
        m = 0
        while l < r:
            m = l + (r - l) // 2
            if matrix[m][0] <= target:
                l = m + 1
            else:
                r = m
        return l - 1

    def searchRow(self, row, target):
        l = 0
        r = len(row)
        m = 0
        while l < r:
            m = l + (r - l) // 2
            if row[m] < target:
                l = m + 1
            elif row[m] == target:
                return True
            else:
                r = m
        return False

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i = self.search(matrix, target)
        if i < 0:
            return False
        return self.searchRow(matrix[i], target)
