class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l = len(prices)
        if l < 2:
            return 0
        forward = [0] * l
        backward = [0] * l
        minPrice = prices[0]
        maxProfit = 0
        for i in range(0, l):
            if prices[i] < minPrice:
                minPrice = prices[i]
            profit = prices[i] - minPrice
            if maxProfit < profit:
                maxProfit = profit
            forward[i] = maxProfit
        maxPrice = prices[l - 1]
        maxProfit = 0
        for i in range(l - 1, -1, -1):
            if maxPrice < prices[i]:
                maxPrice = prices[i]
            profit = maxPrice - prices[i]
            if maxProfit < profit:
                maxProfit = profit
            backward[i] = maxProfit
        maxProfit = 0
        for i in range(0, l):
            profit = forward[i] + backward[i]
            if maxProfit < profit:
                maxProfit = profit
        return maxProfit
