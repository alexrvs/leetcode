class Solution(object):
    def markVisited(self, grid, i, j):
        r = len(grid)
        if r == 0:
            return
        c = len(grid[0])
        grid[i][j] = '0'
        for ia in range(i - 1, i + 2, 2):
            if 0 <= ia and ia < r and grid[ia][j] == '1':
                self.markVisited(grid, ia, j)
        for jb in range(j - 1, j + 2, 2):
            if 0 <= jb and jb < c and grid[i][jb] == '1':
                self.markVisited(grid, i, jb)
        return

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        num = 0
        r = len(grid)
        if r == 0:
            return num
        c = len(grid[0])
        for i in range(0, r):
            for j in range(0, c):
                if grid[i][j] == '1':
                    num += 1
                    self.markVisited(grid, i, j)
        return num
