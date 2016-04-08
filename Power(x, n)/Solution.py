class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1.0
        remain = 1.0
        cur = x
        if n < 0:
            cur = 1.0/cur
            n = -n
        while n > 1:
            if n % 2 != 0:
                remain *= cur
            if n > 1:
                cur *= cur
            n >>= 1
        return cur * remain
