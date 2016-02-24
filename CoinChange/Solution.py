class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        m = amount + 1
        cnts = [ m ] * m
        cnts[0] = 0
        n = len(coins)
        for i in range(0, n):
            if coins[i] < m:
                cnts[coins[i]] = 1
        for i in range(1, m):
            for j in range(0, n):
                prev = i - coins[j]
                if prev >= 1 and cnts[prev] + 1 < cnts[i]:
                    cnts[i] = cnts[prev] + 1
        if cnts[amount] == m:
            return -1
        return cnts[amount]
