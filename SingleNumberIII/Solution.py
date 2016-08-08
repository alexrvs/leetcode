class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        x = 0
        l = len(nums)
        for i in range(0, l):
            x ^= nums[i]
        x &= -x
        res = [ 0 ] * 2
        for i in range(0, l):
            if (x & nums[i]) == 0:
                res[0] ^= nums[i]
            else:
                res[1] ^= nums[i]
        return res
