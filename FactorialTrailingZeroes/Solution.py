class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        zeroes = 0
        while n > 0:
            n = n / 5
            zeroes += n
        return zeroes
