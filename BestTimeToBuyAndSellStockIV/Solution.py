class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        l = len(prices)
        if k >= (l >> 1):
            res = 0
            for i in range(1, l):
                diff = prices[i] - prices[i - 1]
                if diff > 0:
                    res += diff
            return res
        
        dp = []
        for i in range(0, k + 1):
            dp.append([ 0 ] * l)
            if i > 0:
                tmp = dp[i][0] - prices[0]
                for j in range(1, l):
                    dp[i][j] = max(dp[i][j - 1], prices[j] + tmp)
                    tmp = max(tmp, dp[i - 1][j - 1] - prices[j])
        return dp[k][l - 1]