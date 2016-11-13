class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        res = 0
        if l == 0:
            return res
        m = nums[0]
        for i in range(1, l):
            if m > nums[i]:
                m = nums[i]
        for i in range(0, l):
            res += nums[i] - m
        return res