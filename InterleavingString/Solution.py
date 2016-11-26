class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        size1 = len(s1)
        size2 = len(s2)
        size3 = len(s3)
        if size1 + size2 != size3:
            return False
        dp = []
        for i in range(0, size1 + 1):
            dp.append([False] * (size2 + 1))
            for j in range(0, size2 + 1):
                if i == 0 and j == 0:
                    dp[i][j] = True
                elif i == 0:
                    dp[i][j] = (True == dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
                elif j == 0:
                    dp[i][j] = (True == dp[i - 1][j] and s1[i - 1] == s3[i + j - 1])
                else:
                    dp[i][j] = ((True == dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]) or (True == dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]))
        return dp[size1][size2]