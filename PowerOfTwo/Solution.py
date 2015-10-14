class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cnt = 0
        while n > 0:
            if (n & 0x0001) != 0:
                cnt += 1
            n = n >> 1
        if cnt == 1:
            return True
        return False
