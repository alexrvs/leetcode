class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        used = []
        while n > 100 or n not in used:
            if n <= 100:
                used.append(n)
            sum = 0
            while n > 0:
                d = n % 10
                sum += d * d
                n /= 10
            if sum == 1:
                return True
            n = sum
        return False
