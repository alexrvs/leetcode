class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        for i in range(0, numRows):
            row = []
            row.append(1)
            for j in range(1, i):
                row.append(res[i-1][j-1] + res[i-1][j])
            if i > 0:
                row.append(1)
            res.append(row)
        return res
