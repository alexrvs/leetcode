class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        r = len(dungeon)
        if r == 0:
            return 0
        c = len(dungeon[0])
        if c == 0:
            return 0
        needHP = []
        for i in range(0, r):
            needHP.append([ 0 ] * c)
        for i in range(r - 1, -1, -1):
            for j in range(c - 1, -1, -1):
                if i == r - 1 and j == c - 1:
                    needHP[i][j] = max(1, 1 - dungeon[i][j])
                elif i == r - 1:
                    needHP[i][j] = max(1, needHP[i][j + 1] - dungeon[i][j])
                elif j == c - 1:
                    needHP[i][j] = max(1, needHP[i + 1][j] - dungeon[i][j])
                else:
                    needHP[i][j] = max(1, min(needHP[i][j + 1], needHP[i + 1][j]) - dungeon[i][j])
        return needHP[0][0]