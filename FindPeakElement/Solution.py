class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l < 2:
            return 0
        if nums[0] > nums[1]:
            return 0
        for i in range(1, l - 1):
            if nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                return i
        if nums[l - 2] < nums[l - 1]:
            return l - 1
        return 0
