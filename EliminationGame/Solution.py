class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 1
        diff = 1
        time = 1
        while n > 1:
            if time % 2 == 1 or n % 2 == 1:
                start += diff
            time += 1
            n -= (n + 1) / 2
            diff *= 2
        return start