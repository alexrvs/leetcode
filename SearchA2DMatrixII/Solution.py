class Solution(object):
    def searchRow(self, row, target):
        l = 0
        r = len(row)
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
        l = 0
        r = len(matrix)
        while l < r:
            m = l + (r - l) // 2
            if matrix[m][0] <= target:
                l = m + 1
            else:
                r = m
        i = l - 1
        while i >= 0:
            if self.searchRow(matrix[i], target) == True:
                return True
            i -= 1
        return False
