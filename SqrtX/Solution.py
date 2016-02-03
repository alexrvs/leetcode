class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 2:
            return x
        l = 0
        r = x
        while l < r:
            m = l + (r - l) // 2
            if m <= x // m:
                l = m + 1
            else:
                r = m
        return l - 1
