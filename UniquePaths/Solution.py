class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        r = [ 1 ] * n
        p = [ r ] * m
        for i in range(1, m):
            for j in range(1, n):
                p[i][j] = p[i - 1][j] + p[i][j - 1]
        return p[m - 1][n - 1]
