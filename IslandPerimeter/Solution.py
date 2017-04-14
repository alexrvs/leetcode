class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        h = len(grid)
        if h == 0:
            return res
        w = len(grid[0])
        if w == 0:
            return res
        for i in range(0, h):
            for j in range(0, w):
                if grid[i][j] == 1:
                    if i == 0 or grid[i - 1][j] == 0:
                        res += 1
                    if i == h - 1 or grid[i + 1][j] == 0:
                        res += 1
                    if j == 0 or grid[i][j - 1] == 0:
                        res += 1
                    if j == w - 1 or grid[i][j + 1] == 0:
                        res += 1
        return res