class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        zeros = [ 0 ] * 32
        ones = [ 0 ] * 32
        size = len(nums)
        mask = 0x1
        for i in range(0, size):
            tmp = nums[i]
            for j in range(0, 32):
                if (tmp & mask) == 0:
                    zeros[j] += 1
                else:
                    ones[j] += 1
                tmp >>= 1
        res = 0
        for i in range(0, 32):
            res += zeros[i] * ones[i]
        return res