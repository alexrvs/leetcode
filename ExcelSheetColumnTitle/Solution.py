class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret = []
        while n > 0:
            n -= 1
            r = n % 26
            n /= 26
            ret.append(chr(ord('A') + r))
        return ''.join(ret[::-1])
