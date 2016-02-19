class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = len(nums)
        while l < r:
            m = l + (r - l) // 2
            if nums[m] >= nums[0]:
                l = m + 1
            else:
                r = m
        if l >= len(nums):
            return nums[0]
        return nums[l]
