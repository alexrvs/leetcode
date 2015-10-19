class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = len(prices)
        if l < 2:
            return 0
        maxP = 0
        minPrice = prices[0]
        for i in range(1, l):
            if prices[i] < minPrice:
                minPrice = prices[i]
            else:
                profit = prices[i] - minPrice
                if maxP < profit:
                    maxP = profit
        return maxP
