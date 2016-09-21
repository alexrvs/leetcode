class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        ndigits = 1
        upper = 9
        start = 1
        dupper = 9;
        while n > dupper:
            n -= dupper
            ndigits += 1
            start = upper + 1
            upper = start * 10 - 1
            dupper = ndigits * (upper - start + 1)
        start += (n - 1) / ndigits
        n = (n - 1) % ndigits
        digits = [];
        while start > 0:
            digits.append(start % 10)
            start = start / 10
        return digits[ndigits - 1 - n];
