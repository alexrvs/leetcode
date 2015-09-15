class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size <= 1:
            return size
        lastValue = nums[0]
        newSize = 1
        for i in range(1, size):
            if nums[i] != lastValue:
                lastValue = nums[i]
                nums[newSize] = nums[i]
                newSize += 1

        return newSize
