class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l < 2:
            return 0
        for i in range(0, l):
            if i == 0 and nums[i] > nums[i + 1]:
                return i
            if i == l - 1 and nums[i - 1] < nums[i]:
                return i
            if nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                return i
        return 0
