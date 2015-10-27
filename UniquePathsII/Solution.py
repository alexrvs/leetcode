class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        if m == 0:
            return 0
        n = len(obstacleGrid[0])
        p = []
        for i in range(0, m):
            r = [ 0 ] * n
            p.append(r)
        for i in range(0, m):
            if obstacleGrid[i][0] != 1:
                p[i][0] = 1
            else:
                break
        for i in range(0, n):
            if obstacleGrid[0][i] != 1:
                p[0][i] = 1
            else:
                break
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] != 1:
                    a = p[i - 1][j]
                    b = p[i][j - 1]
                    p[i][j] = a + b
        return p[m - 1][n - 1]
