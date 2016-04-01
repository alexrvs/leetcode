class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return n
        i = 0
        while i * i <= n:
            i += 1
        return i - 1
