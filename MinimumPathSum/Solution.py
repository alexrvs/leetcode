class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        h = len(grid)
        if h == 0:
            return 0
        w = len(grid[0])
        for i in range(1, h):
            grid[i][0] += grid[i - 1][0]
        for j in range(1, w):
            grid[0][j] += grid[0][j - 1]
        for i in range(1, h):
            for j in range(1, w):
                if grid[i - 1][j] < grid[i][j - 1]:
                    grid[i][j] += grid[i - 1][j]
                else:
                    grid[i][j] += grid[i][j - 1]
        return grid[h - 1][w - 1]
