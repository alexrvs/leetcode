# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = 1
        r = n
        while l <= r:
            m = l + (r - l) / 2
            if guess(m) > 0:
                l = m + 1
            elif guess(m) == 0:
                return m
            else:
                r = m - 1
        return m
