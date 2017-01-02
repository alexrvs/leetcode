class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        r = len(matrix)
        if r == 0:
            return 0
        c = len(matrix[0])
        dp = []
        maxL = 0
        for i in range(0, r + 1):
            dp.append([0] * (c + 1))
            if i > 0:
                for j in range(1, c + 1):
                    if matrix[i - 1][j - 1] == '1':
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1
                        maxL = max(maxL, dp[i][j])
        return maxL * maxL