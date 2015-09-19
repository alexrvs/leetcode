class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        mask = 0x0001
        i = 0
        num = 0
        while i < 32:
            if (n & mask) != 0:
                num += 1
            mask = mask << 1
            i += 1
        return num
