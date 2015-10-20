class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = len(prices)
        if l < 2:
            return 0
        profit = 0
        for i in range(1, l):
            if prices[i - 1] < prices[i]:
                profit += prices[i] - prices[i - 1]
        return profit
