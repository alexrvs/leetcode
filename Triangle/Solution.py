class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        r = len(triangle)
        if r == 0:
            return 0
        for i in range(1, r):
            for j in range(0, i+1):
                if j == 0:
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j]
                elif j == i:
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1]
                else:
                    t1 = triangle[i][j] + triangle[i - 1][j]
                    t2 = triangle[i][j] + triangle[i - 1][j - 1]
                    if t1 < t2:
                        triangle[i][j] = t1
                    else:
                        triangle[i][j] = t2
        for i in range(1, r):
            if triangle[r - 1][0] > triangle[r - 1][i]:
                triangle[r - 1][0] = triangle[r - 1][i]
        return triangle[r - 1][0]
