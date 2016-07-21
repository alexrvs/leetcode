class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size <= 1:
            return size
        l = 1
        prev = 0
        comm = nums[0]
        for i in range(1, size):
            if prev <= 0 and nums[i] > comm:
                prev = 1
                l += 1
            elif prev >= 0 and nums[i] < comm:
                prev = -1
                l += 1
            comm = nums[i]
        return l
