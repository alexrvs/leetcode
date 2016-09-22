class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 0
        if n % 2 == 0:
            return 1 + self.integerReplacement(n / 2)
        else:
            n1 = self.integerReplacement(n + 1)
            n2 = self.integerReplacement(n - 1)
            if n1 <= n2:
                return 1 + n1
            else:
                return 1 + n2
